#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"

// Structure to hold weather data
typedef struct {
    float temperature;
} WeatherData;

// Function to collect weather data from the user
WeatherData collectWeatherDataFromUser() {
    WeatherData data;
    printf("Enter the temperature: ");
    scanf("%f", &data.temperature);
    return data;
}

// Function to store weather data
void storeWeatherData(WeatherData data) {
    // Simulate storing weather data
    printf("Storing temperature data: %.2f\n", data.temperature);
}

// Function to transmit weather data (dummy implementation)
void transmitWeatherData(WeatherData data) {
    // Simulate transmitting weather data
    printf("Transmitting temperature data: %.2f\n", data.temperature);
}

// Function to analyze weather data (dummy implementation)
void analyzeWeatherData(WeatherData data) {
    // Simulate analyzing weather data
    printf("Analyzing temperature data: %.2f\n", data.temperature);
}

// Function to display weather data to the user
void displayWeatherData(WeatherData data) {
    printf("Current temperature: %.2f\n", data.temperature);
}

// Test functions using MinUnit framework
MU_TEST(testCollectWeatherData) {
    WeatherData data = collectWeatherDataFromUser();
    // Just testing if function doesn't crash, no need to assert
}

MU_TEST(testStoreWeatherData) {
    WeatherData data;
    data.temperature = 30.0;
    storeWeatherData(data); // Just testing if function doesn't crash
}

MU_TEST(testTransmitWeatherData) {
    WeatherData data;
    data.temperature = 20.0;
    transmitWeatherData(data); // Just testing if function doesn't crash
}

MU_TEST(testAnalyzeWeatherData) {
    WeatherData data;
    data.temperature = 25.5;
    analyzeWeatherData(data); // Just testing if function doesn't crash
}

MU_TEST(testDisplayWeatherData) {
    WeatherData data;
    data.temperature = 20.0;
    // Open temporary file for capturing output
    FILE* temp_file = fopen("temp.txt", "w+");
    if (!temp_file) {
        mu_fail("Failed to open temporary file");
        return;
    }
    // Call function that outputs to the file
    displayWeatherData(data);
    // Move file pointer to the beginning to read output
    fseek(temp_file, 0, SEEK_SET);
    // Read and verify output
    char buf[100];
    fgets(buf, sizeof(buf), temp_file);
    mu_assert_string_eq(buf, "Current temperature: 20.00\n");
    // Close the temporary file
    fclose(temp_file);
    // Remove the temporary file
    remove("temp.txt");
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(testCollectWeatherData);
    MU_RUN_TEST(testStoreWeatherData);
    MU_RUN_TEST(testTransmitWeatherData);
    MU_RUN_TEST(testAnalyzeWeatherData);
    MU_RUN_TEST(testDisplayWeatherData);
}

int main() {
    // Run tests
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    // Simulate user interface
    printf("Welcome to Weather Station!\n");
    WeatherData data = collectWeatherDataFromUser();
    displayWeatherData(data);

    return 0;
}
