(*
   Assignment 7: Multi-Paradigm Problem Solving
   OCaml Implementation - Functional Paradigm

   Calculates:
   1. Mean
   2. Median
   3. Mode
   4. Minimum
   5. Maximum
*)

let calculate_mean data =
  let sum = List.fold_left ( + ) 0 data in
  float_of_int sum /. float_of_int (List.length data)

let sorted_data data =
  List.sort compare data

let calculate_median data =
  let sorted = sorted_data data in
  let length = List.length sorted in

  if length mod 2 = 1 then
    float_of_int (List.nth sorted (length / 2))
  else
    let left = List.nth sorted ((length / 2) - 1) in
    let right = List.nth sorted (length / 2) in
    (float_of_int left +. float_of_int right) /. 2.0

let count_occurrences value data =
  List.fold_left
    (fun count element ->
      if element = value then count + 1 else count)
    0
    data

let unique_values data =
  List.sort_uniq compare data

let calculate_mode data =
  let values = unique_values data in

  let frequencies =
    List.map
      (fun value -> (value, count_occurrences value data))
      values
  in

  let max_frequency =
    List.fold_left
      (fun maximum (_, frequency) ->
        max maximum frequency)
      0
      frequencies
  in

  let modes =
    List.filter_map
      (fun (value, frequency) ->
        if frequency = max_frequency then
          Some value
        else
          None)
      frequencies
  in

  (max_frequency, modes)

let calculate_minimum data =
  List.fold_left min max_int data

let calculate_maximum data =
  List.fold_left max min_int data

let print_list data =
  List.iteri
    (fun index value ->
      if index > 0 then
        print_string ", ";
      Printf.printf "%d" value)
    data

let print_modes modes =
  List.iteri
    (fun index value ->
      if index > 0 then
        print_string ", ";
      Printf.printf "%d" value)
    modes

let () =
  let data =
    [
      12; 7; 9; 12; 5;
      7; 12; 15; 9; 7;
      12; 5; 7; 18; 9
    ]
  in

  let (mode_frequency, modes) = calculate_mode data in

  print_endline "==================================================";
  print_endline "       MULTI-PARADIGM STATISTICS - OCAML";
  print_endline "       Functional Programming Approach";
  print_endline "==================================================";

  Printf.printf "Number of values: %d\n" (List.length data);

  print_string "Input data     : ";
  print_list data;
  print_endline "";

  print_endline "";
  print_endline "Statistics";
  print_endline "--------------------------------------------------";

  Printf.printf "Mean           : %.2f\n" (calculate_mean data);
  Printf.printf "Median         : %.2f\n" (calculate_median data);
  Printf.printf "Mode frequency : %d\n" mode_frequency;

  print_string "Mode(s)        : ";

  if mode_frequency = 1 then
    print_endline "No mode (all values occur once)"
  else begin
    print_modes modes;
    print_endline ""
  end;

  Printf.printf "Minimum        : %d\n" (calculate_minimum data);
  Printf.printf "Maximum        : %d\n" (calculate_maximum data);

  print_endline "=================================================="
