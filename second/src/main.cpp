// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
logger::Logger *logger_logger;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace sensor;
using namespace i2c;
i2c::ArduinoI2CBus *i2c_arduinoi2cbus;
preferences::IntervalSyncer *preferences_intervalsyncer;
bme280::BME280Component *bme280_bme280component;
sensor::Sensor *sensor_sensor;
sensor::Sensor *sensor_sensor_2;
sensor::Sensor *sensor_sensor_3;
mdns::MDNSComponent *mdns_mdnscomponent;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: nodemcuv2
  //   framework:
  //     version: 2.7.4
  //     source: ~3.20704.0
  //     platform_version: 2.6.2
  //   restore_from_flash: false
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // esphome:
  //   name: second
  //   build_path: second
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("second", __DATE__ ", " __TIME__, false);
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // wifi:
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   networks:
  //   - ssid: TP-Link_513C
  //     password: '55955430'
  //     id: wifi_wifiap
  //     priority: 0.0
  //   use_address: second.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("second.local");
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("TP-Link_513C");
  wifi_wifiap.set_password("55955430");
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // ota:
  //   password: dimadima
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("dimadima");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   password: dimadima
  //   id: api_apiserver
  //   port: 6053
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("dimadima");
  api_apiserver->set_reboot_timeout(900000);
  // sensor:
  // i2c:
  //   sda: 12
  //   scl: 14
  //   scan: true
  //   id: i2c_arduinoi2cbus
  //   frequency: 50000.0
  i2c_arduinoi2cbus = new i2c::ArduinoI2CBus();
  i2c_arduinoi2cbus->set_component_source("i2c");
  App.register_component(i2c_arduinoi2cbus);
  i2c_arduinoi2cbus->set_sda_pin(12);
  i2c_arduinoi2cbus->set_scl_pin(14);
  i2c_arduinoi2cbus->set_frequency(50000);
  i2c_arduinoi2cbus->set_scan(true);
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // sensor.bme280:
  //   platform: bme280
  //   temperature:
  //     name: bme280_temperature
  //     oversampling: 16X
  //     disabled_by_default: false
  //     id: sensor_sensor
  //     force_update: false
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     device_class: temperature
  //     state_class: measurement
  //   pressure:
  //     name: bme280_pressure
  //     disabled_by_default: false
  //     id: sensor_sensor_2
  //     force_update: false
  //     unit_of_measurement: hPa
  //     accuracy_decimals: 1
  //     device_class: pressure
  //     state_class: measurement
  //     oversampling: 16X
  //   humidity:
  //     name: bme280_humidity
  //     disabled_by_default: false
  //     id: sensor_sensor_3
  //     force_update: false
  //     unit_of_measurement: '%'
  //     accuracy_decimals: 1
  //     device_class: humidity
  //     state_class: measurement
  //     oversampling: 16X
  //   address: 0x76
  //   update_interval: 60s
  //   id: bme280_bme280component
  //   iir_filter: 'OFF'
  //   i2c_id: i2c_arduinoi2cbus
  bme280_bme280component = new bme280::BME280Component();
  bme280_bme280component->set_update_interval(60000);
  bme280_bme280component->set_component_source("bme280.sensor");
  App.register_component(bme280_bme280component);
  bme280_bme280component->set_i2c_bus(i2c_arduinoi2cbus);
  bme280_bme280component->set_i2c_address(0x76);
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("bme280_temperature");
  sensor_sensor->set_disabled_by_default(false);
  sensor_sensor->set_device_class("temperature");
  sensor_sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor->set_unit_of_measurement("\302\260C");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  bme280_bme280component->set_temperature_sensor(sensor_sensor);
  bme280_bme280component->set_temperature_oversampling(bme280::BME280_OVERSAMPLING_16X);
  sensor_sensor_2 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("bme280_pressure");
  sensor_sensor_2->set_disabled_by_default(false);
  sensor_sensor_2->set_device_class("pressure");
  sensor_sensor_2->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_2->set_unit_of_measurement("hPa");
  sensor_sensor_2->set_accuracy_decimals(1);
  sensor_sensor_2->set_force_update(false);
  bme280_bme280component->set_pressure_sensor(sensor_sensor_2);
  bme280_bme280component->set_pressure_oversampling(bme280::BME280_OVERSAMPLING_16X);
  sensor_sensor_3 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_3);
  sensor_sensor_3->set_name("bme280_humidity");
  sensor_sensor_3->set_disabled_by_default(false);
  sensor_sensor_3->set_device_class("humidity");
  sensor_sensor_3->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_3->set_unit_of_measurement("%");
  sensor_sensor_3->set_accuracy_decimals(1);
  sensor_sensor_3->set_force_update(false);
  bme280_bme280component->set_humidity_sensor(sensor_sensor_3);
  bme280_bme280component->set_humidity_oversampling(bme280::BME280_OVERSAMPLING_16X);
  bme280_bme280component->set_iir_filter(bme280::BME280_IIR_FILTER_OFF);
  // socket:
  //   implementation: lwip_tcp
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
