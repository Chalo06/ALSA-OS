#include <stdint.h>

#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_heap_caps.h"

// Identificacion del sistema
#define ALSA_OS_NAME       "ALSA OS"
#define ALSA_OS_VERSION    "0.1.0"

// Etiqueta para los registros
static const char *TAG = "ALSA_OS";

// Punto de entrada del sistema
void app_main(void)
{
    ESP_LOGI(TAG, "================================");

    ESP_LOGI(TAG, "       %s       ", ALSA_OS_NAME);

    ESP_LOGI(TAG, "       Version %s", ALSA_OS_VERSION);

    ESP_LOGI(TAG, "================================");

    ESP_LOGI(TAG, "Inicializando sistema...");

    ESP_LOGI(TAG, "Microcontrolador: ESP32-S3");

    ESP_LOGI(TAG, "Sistema iniciado correctamente");

    // ========================================
// Verificacion de memoria PSRAM
// ========================================

size_t psram_total = heap_caps_get_total_size(MALLOC_CAP_SPIRAM);
size_t psram_libre = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);

ESP_LOGI(TAG, "PSRAM total disponible: %u bytes", (unsigned)psram_total);
ESP_LOGI(TAG, "PSRAM libre: %u bytes", (unsigned)psram_libre);

if (psram_total > 0) {

    ESP_LOGI(TAG, "PSRAM detectada correctamente");

    // Probar una reserva de memoria de 1 MB
    void *test = heap_caps_malloc(
        1024 * 1024,
        MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT
    );

    if (test != NULL) {
        ESP_LOGI(TAG, "Reserva de 1 MB en PSRAM exitosa");

        heap_caps_free(test);
    } else {
        ESP_LOGE(TAG, "Error reservando memoria PSRAM");
    }

} else {
    ESP_LOGE(TAG, "No se detecto PSRAM disponible");
}

    // Bucle principal
    while (1)
    {
        ESP_LOGI(TAG, "ALSA OS funcionando...");

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}