#include <amf0.h>

Amf0GenericInvokeMessage *amf0_create_generic_invoke_message() {
  Amf0GenericInvokeMessage *msg = malloc(sizeof(Amf0GenericInvokeMessage));
  msg->command = NULL;
  msg->description = NULL;

  return msg;
}

void amf0_destroy_generic_invoke_message(Amf0GenericInvokeMessage *msg) {
  bdestroy(msg->command);
  bdestroy(msg->description);
  // msg->transaction_id = 0.0;
  // if (msg->arguments != NULL) amf0_destroy_object(msg->arguments);
}


int amf0_serialize_generic_invoke_message(unsigned char *output, Amf0GenericInvokeMessage *msg) {
  int i = 0;

  i += amf0_serialize_string(output + i, msg->command);
  i += amf0_serialize_string(output + i, msg->description);
  // i += amf0_serialize_object(output + i, msg->arguments);

  return i;
}

int amf0_deserialize_generic_invoke_message(Amf0GenericInvokeMessage *msg, unsigned char *input) {
  unsigned int start = (unsigned int)input;

  input++;
  input += amf0_deserialize_string(&(msg->command), input);

  input++;
  input += amf0_deserialize_string(&(msg->description), input);

  // if (input[0] == AMF0_NULL) {
  //   msg->arguments = NULL;
  //   input++;
  // } else {
  //   input++;
  //   input += amf0_deserialize_object(&(msg->arguments), input);
  // }

  return (unsigned int)input - start;
}



Amf0ConnectMessage *amf0_create_connect_message() {
  Amf0ConnectMessage *msg = malloc(sizeof(Amf0ConnectMessage));
  msg->command = NULL;
  msg->transaction_id = 0.0;
  msg->arguments = NULL;

  return msg;
}

void amf0_destroy_connect_message(Amf0ConnectMessage *msg) {
  bdestroy(msg->command);
  msg->transaction_id = 0.0;
  if (msg->arguments != NULL) amf0_destroy_object(msg->arguments);
}


int amf0_serialize_connect_message(unsigned char *output, Amf0ConnectMessage *msg) {
  int i = 0;

  i += amf0_serialize_string(output + i, msg->command);
  i += amf0_serialize_number(output + i, msg->transaction_id);
  i += amf0_serialize_object(output + i, msg->arguments);

  return i;
}

int amf0_deserialize_connect_message(Amf0ConnectMessage *msg, unsigned char *input) {
  unsigned int start = (unsigned int)input;

  input++;
  input += amf0_deserialize_string(&(msg->command), input);

  input++;
  input += amf0_deserialize_number(&(msg->transaction_id), input);

  if (input[0] == AMF0_NULL) {
    msg->arguments = NULL;
    input++;
  } else {
    input++;
    input += amf0_deserialize_object(&(msg->arguments), input);
  }

  return (unsigned int)input - start;
}



Amf0ResponseConnectMessage *amf0_create_response_connect_message() {
  Amf0ResponseConnectMessage *msg = malloc(sizeof(Amf0ResponseConnectMessage));
  msg->command = NULL;
  msg->transaction_id = 0.0;
  msg->properties = NULL;
  msg->information = NULL;

  return msg;
}

void amf0_destroy_response_connect_message(Amf0ResponseConnectMessage *msg) {
  bdestroy(msg->command);
  msg->transaction_id = 0.0;
  amf0_destroy_object(msg->properties);
  amf0_destroy_object(msg->information);
}

int amf0_serialize_response_connect_message(unsigned char *output, Amf0ResponseConnectMessage *msg) {
  int i = 0;

  i += amf0_serialize_string(output + i, msg->command);
  i += amf0_serialize_number(output + i, msg->transaction_id);
  i += amf0_serialize_object(output + i, msg->properties);
  i += amf0_serialize_object(output + i, msg->information);

  return i;
}

int amf0_deserialize_response_connect_message(Amf0ResponseConnectMessage *msg, unsigned char *input) {
  unsigned int start = (unsigned int)input;

  input++;
  input += amf0_deserialize_string(&(msg->command), input);

  input++;
  input += amf0_deserialize_number(&(msg->transaction_id), input);

  if (input[0] == AMF0_NULL) {
    msg->properties = NULL;
    input++;
  } else {
    input++;
    input += amf0_deserialize_object(&(msg->properties), input);
  }

  if (input[0] == AMF0_NULL) {
    msg->information = NULL;
    input++;
  } else {
    input++;
    input += amf0_deserialize_object(&(msg->information), input);
  }

  return (unsigned int)input - start;
}


Amf0CreateStreamMessage *amf0_create_create_stream_message() {
  Amf0CreateStreamMessage *msg = malloc(sizeof(Amf0CreateStreamMessage));
  msg->command = NULL;
  msg->transaction_id = 0.0;
  msg->object = NULL;

  return msg;
}

void amf0_destroy_create_stream_message(Amf0CreateStreamMessage *msg) {
  bdestroy(msg->command);
  msg->transaction_id = 0.0;
  if (msg->object != NULL) amf0_destroy_object(msg->object);
}

Amf0ResponseCreateStreamMessage *amf0_create_response_create_stream_message() {
  Amf0ResponseCreateStreamMessage *msg = malloc(sizeof(Amf0ResponseCreateStreamMessage));
  msg->command = NULL;
  msg->transaction_id = 0.0;
  msg->object = NULL;
  msg->stream_id = 0.0;

  return msg;
}

void amf0_destroy_response_create_stream_message(Amf0ResponseCreateStreamMessage *msg) {
  bdestroy(msg->command);
  msg->transaction_id = 0.0;
  if (msg->object != NULL) amf0_destroy_object(msg->object);
  msg->stream_id = 0.0;
}

int amf0_serialize_create_stream_message(unsigned char *output, Amf0CreateStreamMessage *msg) {
  int i = 0;

  i += amf0_serialize_string(output + i, msg->command);
  i += amf0_serialize_number(output + i, msg->transaction_id);
  i += amf0_serialize_object(output + i, msg->object);

  return i;
}

int amf0_deserialize_create_stream_message(Amf0CreateStreamMessage *msg, unsigned char *input) {
  unsigned int start = (unsigned int)input;

  input++;
  input += amf0_deserialize_string(&(msg->command), input);

  input++;
  input += amf0_deserialize_number(&(msg->transaction_id), input);

  if (input[0] == AMF0_NULL) {
    msg->object = NULL;
    input++;
  } else {
    input++;
    input += amf0_deserialize_object(&(msg->object), input);
  }

  return (unsigned int)input - start;
}

int amf0_serialize_response_create_stream_message(unsigned char *output, Amf0ResponseCreateStreamMessage *msg) {
  int i = 0;

  i += amf0_serialize_string(output + i, msg->command);
  i += amf0_serialize_number(output + i, msg->transaction_id);
  i += amf0_serialize_object(output + i, msg->object);
  i += amf0_serialize_number(output + i, msg->stream_id);
  
  return i;
}

int amf0_deserialize_response_create_stream_message(Amf0ResponseCreateStreamMessage *msg, unsigned char *input) {
  unsigned int start = (unsigned int)input;

  input++;
  input += amf0_deserialize_string(&(msg->command), input);

  input++;
  input += amf0_deserialize_number(&(msg->transaction_id), input);

  if (input[0] == AMF0_NULL) {
    msg->object = NULL;
    input++;
  } else {
    input++;
    input += amf0_deserialize_object(&(msg->object), input);
  }

  input++;
  input += amf0_deserialize_number(&(msg->stream_id), input);

  return (unsigned int)input - start;
}

Amf0PublishMessage *amf0_create_publish_message() {
  Amf0PublishMessage *msg = malloc(sizeof(Amf0PublishMessage));
  msg->command = NULL;
  msg->transaction_id = 0.0;
  msg->publishing_name = NULL;
  msg->publishing_type = NULL;

  return msg;
}

void amf0_destroy_publish_message(Amf0PublishMessage *msg) {
  if (msg->command != NULL) bdestroy(msg->command);
  msg->transaction_id = 0.0;
  if (msg->publishing_name != NULL) bdestroy(msg->publishing_name);
  if (msg->publishing_type != NULL) bdestroy(msg->publishing_type);
}

int amf0_serialize_publish_message(unsigned char *output, Amf0PublishMessage *msg) {
  int i = 0;

  i += amf0_serialize_string(output + i, msg->command);
  i += amf0_serialize_number(output + i, msg->transaction_id);
  i += amf0_serialize_null(output + i);
  i += amf0_serialize_string(output + i, msg->publishing_name);
  i += amf0_serialize_string(output + i, msg->publishing_type);
  
  return i;
}

int amf0_deserialize_publish_message(Amf0PublishMessage *msg, unsigned char *input) {
  unsigned int start = (unsigned int)input;

  input++;
  input += amf0_deserialize_string(&(msg->command), input);

  input++;
  input += amf0_deserialize_number(&(msg->transaction_id), input);

  // null type
  input++;

  input++;
  input += amf0_deserialize_string(&(msg->publishing_name), input);

  input++;
  input += amf0_deserialize_string(&(msg->publishing_type), input);

  return (unsigned int)input - start;
}









void amf0_destroy_object(Hashmap *object) {
  if (object == NULL) return;

  int i = 0;
  int j = 0;

  for(i = 0; i < DArray_count(object->buckets); i++) {
      DArray *bucket = DArray_get(object->buckets, i);
      if(bucket) {
          for(j = 0; j < DArray_count(bucket); j++) {
              HashmapNode *node = DArray_get(bucket, j);

              free(node->key);
              amf0_destroy_object_value(node->data);
          }
      }
  }

  Hashmap_destroy(object);
}

void amf0_destroy_object_value(Amf0ObjectValue *object) {
  if (object->type == AMF0_STRING) bdestroy(object->string);
  else if (object->type == AMF0_OBJECT) amf0_destroy_object(object->object);
  else if (object->type == AMF0_TYPED_OBJECT) amf0_destroy_typed_object(object->typed_object);
  else if (object->type == AMF0_ECMA_ARRAY) amf0_destroy_ecma_array(object->ecma_array);
  else if (object->type == AMF0_STRICT_ARRAY) amf0_destroy_strict_array(object->strict_array);
  else if (object->type == AMF0_XML_DOCUMENT) bdestroy(object->xml_document);
  else if (object->type == AMF0_LONG_STRING) bdestroy(object->string);

  free(object);
}

void amf0_destroy_typed_object(Amf0TypedObject *object) {
  amf0_destroy_object(object->object);
  bdestroy(object->class_name);

  free(object);
}

void amf0_destroy_ecma_array(Hashmap *emca_array) {
  amf0_destroy_object(emca_array);
}

void amf0_destroy_strict_array(Amf0StrictArray *strict_array) {
  int i;
  for (i=0;i<strict_array->length;i++) {
    amf0_destroy_object_value(strict_array->data[i]);
  }

  free(strict_array->data);
  free(strict_array);
}

int amf0_serialize_number(unsigned char *output, double number) {
  output[0] = AMF0_NUMBER;
  memcpy(output + 1, &number, 8);

  int i;
  for (i=0;i<4;i++) {
    unsigned char b = output[i+1];
    output[i+1] = output[8-i];
    output[8-i] = b;
  }

  return 9;
}

int amf0_deserialize_number(double *number, unsigned char *input) {
  int i;
  for (i=0;i<8;i++) {
    memcpy((char *)number + i, input + 7 - i, 1);
  }

  return 8;
}

int amf0_serialize_boolean(unsigned char *output, int boolean) {
  output[0] = AMF0_BOOLEAN;
  output[1] = (boolean == 0) ? 0x00 : 0x01;

  return 2;
}

int amf0_deserialize_boolean(int *boolean, unsigned char *input) {
  (*boolean) = (input[0] == 0) ? 0 : 1;
  return 1;
}


int amf0_serialize_string(unsigned char *output, bstring str) {
  int i = 0;
  output[i++] = AMF0_STRING;

  i += amf0_serialize_string_literal(output + i, str, 2);

  return i;
}

int amf0_deserialize_string(bstring *output, unsigned char *input) {
  int length = chars_to_int(input, 2);

  int check = amf0_deserialize_string_literal(output, input + 2, length);
  if (check == -1) return -1;

  return 2 + length;
}

int amf0_serialize_string_literal(unsigned char *output, bstring str, int length_of_length) {
  int_to_byte_array(str->slen, output, 0, length_of_length);

  int i;
  for (i=0;i<str->slen;i++) {
    output[i + length_of_length] = str->data[i];
  }

  return str->slen + length_of_length;
}

int amf0_deserialize_string_literal(bstring *output, unsigned char *input, int length) {
  char tmp[length + 1];

  memcpy(tmp, input, length);
  tmp[length] = '\0';

  bstring str = bfromcstr(tmp);
  (*output) = str;
  return length;
}


int amf0_serialize_object(unsigned char *output, Hashmap *object) {
  int count = 0;
  
  if (object == NULL) {
    output[0] = AMF0_NULL;
    return 1;
  }

  output[count++] = AMF0_OBJECT;

  count += amf0_serialize_object_content(output + count, object);

  output[count++] = 0x00;
  output[count++] = 0x00;
  output[count++] = 0x09;

  return count;
}


int amf0_serialize_object_content(unsigned char *output, Hashmap *object) {
  int count = 0;
  int i = 0;
  int j = 0;
  int rc = 0;

  for(i = 0; i < DArray_count(object->buckets); i++) {
      DArray *bucket = DArray_get(object->buckets, i);
      if(bucket) {
          for(j = 0; j < DArray_count(bucket); j++) {
              HashmapNode *node = DArray_get(bucket, j);

              // serialize key
              count += amf0_serialize_string_literal(output + count, node->key, 2);
              count += amf0_serialize_object_value(output + count, (Amf0ObjectValue *)node->data);

              if(rc != 0) return rc;
          }
      }
  }

  return count;
}

int amf0_deserialize_object(Hashmap **output_pointer, unsigned char *input) {
  unsigned int start = (unsigned int)input;

  (*output_pointer) = Hashmap_create(NULL, NULL);

  while (!(input[0] == 0x00 && input[1] == 0x00 && input[2] == 0x09)) {
    bstring key;
    Amf0ObjectValue *value;

    input += amf0_deserialize_string(&key, input);
    input += amf0_deserialize_object_value(&value, input);

    Hashmap_set(*output_pointer, key, value);
  }

  return (unsigned int)input + 3 - start;
}

int amf0_serialize_object_value(unsigned char *output, Amf0ObjectValue *val) {
  if (val->type == AMF0_NUMBER) {
    return amf0_serialize_number(output, val->number);
  } else if (val->type == AMF0_BOOLEAN) {
    return amf0_serialize_boolean(output, val->boolean);
  } else if (val->type == AMF0_STRING) {
    return amf0_serialize_string(output, val->string);
  } else if (val->type == AMF0_OBJECT) {
    return amf0_serialize_object(output, val->object);
  } else if (val->type == AMF0_MOVIE_CLIP) {
    return amf0_serialize_movie_clip(output);
  } else if (val->type == AMF0_NULL) {
    return amf0_serialize_null(output);
  } else if (val->type == AMF0_UNDEFINED) {
    return amf0_serialize_undefined(output);
  } else if (val->type == AMF0_REFERENCE) {
    return amf0_serialize_reference(output, val->reference);
  } else if (val->type == AMF0_ECMA_ARRAY) {
    return amf0_serialize_ecma_array(output, val->ecma_array);
  } else if (val->type == AMF0_STRICT_ARRAY) {
    return amf0_serialize_strict_array(output, val->strict_array);
  } else if (val->type == AMF0_DATE) {
    return amf0_serialize_date(output, val->date);
  } else if (val->type == AMF0_LONG_STRING) {
    return amf0_serialize_long_string(output, val->string);
  } else if (val->type == AMF0_UNSUPPORTED) {
    return amf0_serialize_unsupported(output);
  } else if (val->type == AMF0_RECORDSET) {
    return amf0_serialize_record_set(output);
  } else if (val->type == AMF0_XML_DOCUMENT) {
    return amf0_serialize_xml_document(output, val->xml_document);
  } else if (val->type == AMF0_TYPED_OBJECT) {
    return amf0_serialize_typed_object(output, val->typed_object);
  } else {
    return 0;
  }
}

int amf0_deserialize_object_value(Amf0ObjectValue **output_pointer, unsigned char *input) {
  unsigned char *start_data = (unsigned char *)((unsigned int)input + 1);
  int count = 0;

  //printf("%02x ", input[0]);

  *output_pointer = malloc(sizeof(Amf0ObjectValue));
  Amf0ObjectValue *output = *output_pointer;
  output->type = input[0];

  if (output->type == AMF0_NUMBER) {
    count = amf0_deserialize_number(&(output->number), start_data);
  } else if (output->type == AMF0_BOOLEAN) {
    count = amf0_deserialize_boolean(&(output->boolean), start_data);
  } else if (output->type == AMF0_STRING) {
    count = amf0_deserialize_string(&(output->string), start_data);
  } else if (output->type == AMF0_OBJECT) {
    count = amf0_deserialize_object(&(output->object), start_data);
  } else if (output->type == AMF0_MOVIE_CLIP) {
    count = amf0_deserialize_movie_clip(start_data);
  } else if (output->type == AMF0_NULL) {
    count = amf0_deserialize_null(start_data);
  } else if (output->type == AMF0_UNDEFINED) {
    count = amf0_deserialize_undefined(start_data);
  } else if (output->type == AMF0_REFERENCE) {
    count = amf0_deserialize_reference(&(output->reference), start_data);
  } else if (output->type == AMF0_ECMA_ARRAY) {
    count = amf0_deserialize_ecma_array(&(output->ecma_array), start_data);
  } else if (output->type == AMF0_OBJECT_END) {
    printf("wtf! this is object-end-marker\n");
    exit(1);
  } else if (output->type == AMF0_STRICT_ARRAY) {
    count = amf0_deserialize_strict_array(&(output->strict_array), start_data);
  } else if (output->type == AMF0_DATE) {
    count = amf0_deserialize_date(&(output->date), start_data);
  } else if (output->type == AMF0_LONG_STRING) {
    count = amf0_deserialize_long_string(&(output->string), start_data);
  } else if (output->type == AMF0_UNSUPPORTED) {
    count = amf0_deserialize_unsupported(start_data);
  } else if (output->type == AMF0_RECORDSET) {
    count = amf0_deserialize_record_set(start_data);
  } else if (output->type == AMF0_XML_DOCUMENT) {
    count = amf0_deserialize_xml_document(&(output->xml_document), start_data);
  } else if (output->type == AMF0_TYPED_OBJECT) {
    count = amf0_deserialize_typed_object(&(output->typed_object), start_data);
  } else {
    count = 0;
  }

  return count + 1;
}


void print_amf0_object(Hashmap *object) {
  int i = 0;
  int j = 0;

  for(i = 0; i < DArray_count(object->buckets); i++) {
      DArray *bucket = DArray_get(object->buckets, i);
      if(bucket) {
          for(j = 0; j < DArray_count(bucket); j++) {
              HashmapNode *node = DArray_get(bucket, j);

              printf("\t%s -> ", bdata((bstring)(node->key)));
              print_amf0_object_value(node->data);
              printf("\n");
          }
      }
  }
}

void print_amf0_object_value(Amf0ObjectValue *val) {
  if (val->type == AMF0_NUMBER) {
    printf("%f", val->number);
  } else if (val->type == AMF0_BOOLEAN) {
    printf("%d", val->boolean);
  } else if (val->type == AMF0_STRING) {
    printf("%s", bdata(val->string));
  } else if (val->type == AMF0_OBJECT) {
    print_amf0_object(val->object);
  } else if (val->type == AMF0_MOVIE_CLIP) {
    printf("<movie_clip>");
  } else if (val->type == AMF0_NULL) {
    printf("<null>");
  } else if (val->type == AMF0_UNDEFINED) {
    printf("<undefined>");
  } else if (val->type == AMF0_REFERENCE) {
    printf("%d", val->reference);
  } else if (val->type == AMF0_ECMA_ARRAY) {
    print_amf0_ecma_array(val->ecma_array);
  } else if (val->type == AMF0_STRICT_ARRAY) {
    print_amf0_strict_array(val->strict_array);
  } else if (val->type == AMF0_DATE) {
    printf("%f (seconds from epoch)", val->date);
  } else if (val->type == AMF0_LONG_STRING) {
    printf("%s", bdata(val->string));
  } else if (val->type == AMF0_UNSUPPORTED) {
    printf("<unsupported>");
  } else if (val->type == AMF0_RECORDSET) {
    printf("<record_set>");
  } else if (val->type == AMF0_XML_DOCUMENT) {
    printf("%s", bdata(val->xml_document));
  } else if (val->type == AMF0_TYPED_OBJECT) {
    printf("%s {", bdata(val->typed_object->class_name));
    print_amf0_object(val->typed_object->object);
    printf("}");
  } else {
    printf("Unknown");
  }
}


int amf0_serialize_movie_clip(unsigned char *output) {
  (void)output;
  printf("Serialize MovieClip is not supported.\n");
  exit(1);
  return 0;
}

int amf0_deserialize_movie_clip(unsigned char *input) {
  (void)input;
  printf("Deserialize MovieClip is not supported.\n");
  exit(1);
  return 0;
}


int amf0_serialize_null(unsigned char *output) {
  (void)output;
  output[0] = AMF0_NULL;
  return 1;
}

int amf0_deserialize_null(unsigned char *input) {
  (void)input;
  return 0;
}


int amf0_serialize_undefined(unsigned char *output) {
  (void)output;
  output[0] = AMF0_UNDEFINED;
  return 1;
}

int amf0_deserialize_undefined(unsigned char *input) {
  (void)input;
  return 0;
}


int amf0_serialize_reference(unsigned char *output, unsigned short reference) {
  output[0] = AMF0_REFERENCE;
  output[1] = ((reference & 0xFF00) >> 8);
  output[2] = (reference & 0x00FF);

  return 3;
}

int amf0_deserialize_reference(unsigned short *reference, unsigned char *input) {
  *reference = ((unsigned short)(input[0]) << 8) | (unsigned short)input[1];
  return 2;
}

int amf0_serialize_ecma_array(unsigned char *output, Hashmap *array) {
  int count = 0;
  output[count++] = AMF0_ECMA_ARRAY;

  // length
  output[count++] = 0x00;
  output[count++] = 0x00;
  output[count++] = 0x00;
  output[count++] = 0x00;

  int i = 0;
  int j = 0;

  for(i = 0; i < DArray_count(array->buckets); i++) {
      DArray *bucket = DArray_get(array->buckets, i);
      if(bucket) {
          for(j = 0; j < DArray_count(bucket); j++) {
              HashmapNode *node = DArray_get(bucket, j);

              count += amf0_serialize_string_literal(output + count, node->key, 2);
              count += amf0_serialize_object_value(output + count, (Amf0ObjectValue *)node->data);
          }
      }
  }


  output[count++] = 0x00;
  output[count++] = 0x00;
  output[count++] = 0x09;

  return count;
}

int amf0_deserialize_ecma_array(Hashmap **output_pointer, unsigned char *input) {
  unsigned int start = (unsigned int)input;
  input += 4; // skip length (4 bytes)

  *output_pointer = Hashmap_create(NULL, NULL);

  while (!(input[0] == 0x00 && input[1] == 0x00 && input[2] == 0x09)) {
    bstring key;
    Amf0ObjectValue *value;

    input += amf0_deserialize_string(&key, input);
    input += amf0_deserialize_object_value(&value, input);

    Hashmap_set(*output_pointer, key, value);
  }

  return (unsigned int)input + 3 - start;
}

void print_amf0_ecma_array(Hashmap *array) {
  print_amf0_object(array);
}


int amf0_serialize_strict_array(unsigned char *output, Amf0StrictArray *array) {
  int count = 0;

  output[count++] = AMF0_STRICT_ARRAY;

  int_to_byte_array(array->length, output, count, 4);
  count += 4;

  int i;
  for (i=0;i<array->length;i++) {
    count += amf0_serialize_object_value(output + count, array->data[i]);
  }

  return count;
}

int amf0_deserialize_strict_array(Amf0StrictArray **array, unsigned char *input) {
  int count = 0;

  unsigned int length = chars_to_int(input, 4);
  count += 4;

  (*array) = malloc(sizeof(Amf0StrictArray));
  (*array)->length = length;
  (*array)->data = calloc(length, sizeof(Amf0ObjectValue *));

  unsigned int i;
  for (i=0;i<length;i++) {
    count += amf0_deserialize_object_value(&((*array)->data[i]), input + count); 
  }

  return count;
}

void print_amf0_strict_array(Amf0StrictArray *array) {
  printf("[");
  int i;
  for (i=0;i<array->length;i++) {
    if (i > 0) printf(", ");
    print_amf0_object_value(array->data[i]);
  }
  printf("]");
}

int amf0_serialize_date(unsigned char *output, double date) {
  output[0] = AMF0_DATE;
  memcpy(output + 1, &date, 8);

  int i;
  for (i=0;i<4;i++) {
    unsigned char b = output[i+1];
    output[i+1] = output[8-i];
    output[8-i] = b;
  }

  return 9;
}

int amf0_deserialize_date(double *date, unsigned char *input) {
  int i;
  for (i=0;i<8;i++) {
    memcpy((char *)date + i, input + 7 - i, 1);
  }

  return 8;
}


int amf0_serialize_long_string(unsigned char *output, bstring str) {
  int i = 0;
  output[i++] = AMF0_LONG_STRING;

  i += amf0_serialize_string_literal(output + i, str, 4);

  return i;
}

int amf0_deserialize_long_string(bstring *output, unsigned char *input) {
  unsigned int length = chars_to_int(input, 4);

  int check = amf0_deserialize_string_literal(output, input + 4, length);
  if (check == -1) return -1;

  return 4 + length;
}


int amf0_serialize_unsupported(unsigned char *output) {
  (void) output;
  output[0] = AMF0_UNSUPPORTED;
  return 1;
}

int amf0_deserialize_unsupported(unsigned char *input) {
  (void) input;
  return 0;
}

int amf0_serialize_record_set(unsigned char *output) {
  (void) output;
  printf("RecordSet is not supported");
  exit(1);
}

int amf0_deserialize_record_set(unsigned char *input) {
  (void) input;
  printf("RecordSet is not supported");
  exit(1);
}

int amf0_serialize_xml_document(unsigned char *output, bstring str) {
  int i = 0;
  output[i++] = AMF0_XML_DOCUMENT;

  i += amf0_serialize_string_literal(output + i, str, 4);

  return i;
}

int amf0_deserialize_xml_document(bstring *output, unsigned char *input) {
  unsigned int length = chars_to_int(input, 4);

  int check = amf0_deserialize_string_literal(output, input + 4, length);
  if (check == -1) return -1;

  return 4 + length;
}

int amf0_serialize_typed_object(unsigned char *output, Amf0TypedObject *typed_object) {
  int count = 0;
  output[count++] = AMF0_TYPED_OBJECT;

  count += amf0_serialize_string_literal(output + count, typed_object->class_name, 2);
  count += amf0_serialize_object_content(output + count, typed_object->object);

  output[count++] = 0x00;
  output[count++] = 0x00;
  output[count++] = 0x09;

  return count;
}

int amf0_deserialize_typed_object(Amf0TypedObject **output_pointer, unsigned char *input) {
  (*output_pointer) = malloc(sizeof(Amf0TypedObject));

  Amf0TypedObject *output = *output_pointer;

  unsigned int start = (unsigned int) input;
  input += amf0_deserialize_string(&(output->class_name), input);
  
  output->object = Hashmap_create(NULL, NULL);

  while (!(input[0] == 0x00 && input[1] == 0x00 && input[2] == 0x09)) {
    bstring key;
    Amf0ObjectValue *value;

    input += amf0_deserialize_string(&key, input);
    input += amf0_deserialize_object_value(&value, input);
    
    Hashmap_set(output->object, key, value);
  }

  return (unsigned int) input + 3 - start;
}



void amf0_parse(unsigned char *message, int start, int msg_length) {

  printf("Parse %d %d\n", start, msg_length);

  int i,j;
  for (i=start;i<(start + msg_length);i++) {

    printf("type = %u\n", message[i]);

    if (message[i] == 0x02) {
      int length = chars_to_int(message + i + 1, 2);

      i += 3;
      for (j=0;j<length;j++)
        printf("%c", message[i + j]);
      printf("\n");

      i += length - 1;
    } else if (message[i] == 0x00) {
      double number = chars_to_double(message + i + 1, 8);
      printf("%f\n", number);
      i += 1 + 8 - 1;
    } else if (message[i] == 0x03) {
      printf("Start-object\n");
      int length = chars_to_int(message + i + 1, 2);

      i += 3;
      for (j=0;j<length;j++)
        printf("%c", message[i + j]);
      printf("\n");

      i += length - 1;
      i++;
      length = chars_to_int(message + i + 1, 4);

      i += 5;
      for (j=0;j<length;j++)
        printf("%c", message[i + j]);
      printf("\n");

      i += length - 1;
    } else if (message[i] == 0x09) {
      printf("End-object\n");
    } else if (message[i] == 0x08) {
      printf("End-object\n");
    } else {
      break;
    }
  }
}