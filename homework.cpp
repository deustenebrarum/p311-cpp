//#include <iostream>
//
//size_t bubble_sort_count(int array[], size_t size) {
//	size_t count = 0;
//	for (size_t _ = 0; _ < size; _++)
//	{
//		bool is_sorted = true;
//		for (size_t i = 0; i < size; i++)
//		{
//			if (array[i] > array[i + 1])
//			{
//				is_sorted = false;
//				int temp = array[i];
//				array[i] = array[i + 1];
//				array[i + 1] = temp;
//
//				count++;
//			}
//		}
//		if (is_sorted) break;
//	}
//
//	return count;
//}
//
//void many_sorts() {
//	const size_t size = 1000;
//	int array[size];
//	for (size_t i = 0; i < size; i++) {
//		array[i] = rand();
//	}
//
//	size_t count = bubble_sort_count(array, size);
//
//	std::cout << count << '\n';
//}
//
//void reverse(int array[], size_t from, size_t to) {
//	for (size_t i = from, j = to - 1; i < j; i++, j--) {
//		int temp = array[i];
//		array[i] = array[j];
//		array[j] = temp;
//	}
//}
//
//size_t find_max(int array[], size_t from, size_t to) {
//	size_t max_index = 0;
//
//	for (size_t i = from; i < to; i++) {
//		if (array[i] > array[i + 1]) {
//			max_index = i;
//		}
//	}
//
//	return max_index;
//}
//
//void pancake_sort(
//	int array[],
//	size_t size
//) {
//	for (size_t i = 0; i < size; i++)
//	{
//		size_t max_index = find_max(array, i, size);
//
//		reverse(array, max_index, size);
//		reverse(array, i, size);
//	}
//}
//
//void not_main() {
//	int array[5] { 1, 3, 2, 5, 4 };
//	pancake_sort(array, 5);
//}
//
//void sort_directory(
//	int mobile_numbers[], int home_numbers[],
//	int array_to_compare[],
//	size_t size
//) {
//	for (size_t _ = 0; _ < size; _++)
//	{
//		for (size_t j = 0; j < size - 1; j++)
//		{
//			if (array_to_compare[j] > array_to_compare[j + 1])
//			{
//				int temp = mobile_numbers[j];
//				mobile_numbers[j] = mobile_numbers[j + 1];
//				mobile_numbers[j + 1] = temp;
//
//				temp = home_numbers[j];
//				home_numbers[j] = home_numbers[j + 1];
//				home_numbers[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void dz_directory() {
//	const size_t size = 5;
//	int mobile_numbers[size]{ 1, 2, 5, 4, 3 };
//	int home_numbers[size]{ 21, 92, 45, 74, 33 };
//
//	int menu_choice;
//	std::cin >> menu_choice;
//
//	switch (menu_choice) {
//	case 1:
//		sort_directory(mobile_numbers, home_numbers, mobile_numbers, size);
//		break;
//	case 2:
//		sort_directory(mobile_numbers, home_numbers, home_numbers, size);
//		break;
//	}
//
//}
//
//void dz1() {
//	const size_t size = 12;
//	float currency_rates[size]{ 2, 1.5, 1.8, 1.7, 1.8, 2, 1.9, 2.1 };
//	float month_additions[size]{ 1.05, 1.03, 1.2, 1.1, 1.07, 1.04, 1.06, 1.03 };
//
//	float start_account_money = 100000;
//
//	float account_money = start_account_money;
//
//	size_t selected_month = 5;
//
//	for (size_t i = 0; i < selected_month; i++)
//	{
//		account_money *= month_additions[i];
//	}
//
//	float last_month_addition = (
//		account_money - account_money / month_additions[selected_month - 1]
//		);
//
//	if (last_month_addition * currency_rates[selected_month - 1] > 500) {
//		float withdraw_sum = (account_money - start_account_money);
//		withdraw_sum *= 0.5 * currency_rates[selected_month - 1];
//		std::cout << "You can withdraw " << withdraw_sum;
//	}
//	else {
//		std::cout << "You can't withdraw";
//	}
//}
