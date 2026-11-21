// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CreativeDataChannelTypes.generated.h"

USTRUCT(BlueprintType)
struct FCDCStringFloatArrayMap
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCStringFloatArrayMap")
	TMap<FString, FVector> Data;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventFloatArrayMapRep, FCDCStringFloatArrayMap, EventMap);

USTRUCT(BlueprintType)
struct FCDCFloatArray
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCFloatArray")
	TArray<float> Data;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventFloatArrayRep, FCDCFloatArray, EventMap);

USTRUCT(BlueprintType)
struct FCDCStringFloatMap
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCStringFloatMap")
	TMap<FString, float> Data;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventFloatMapRep, FCDCStringFloatMap, EventMap);

USTRUCT(BlueprintType)
struct FCDCStringIntMap
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCStringIntMap")
	TMap<FString, int32> Data;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventIntMapRep, FCDCStringIntMap, EventMap);

USTRUCT(BlueprintType)
struct FCDCInt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCInt")
	int32 Data;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventIntRep, FCDCInt, EventNumber);

USTRUCT(BlueprintType)
struct FCDCLargeInt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCLargeInt")
	int64 Data;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventLargeIntRep, FCDCLargeInt, EventNumber);

USTRUCT(BlueprintType)
struct FCDCStringStringMap
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCStringStringMap")
	TMap<FString, FString> Data;

	UPROPERTY(BlueprintReadOnly, Category="CDCStringStringMap")
	TMap<FString, int32> ExtraData;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventStringMapRep, FCDCStringStringMap, EventMap);

USTRUCT(BlueprintType)
struct FCDCString
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCString")
	FString Data;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCEventStringRep, FCDCString, EventString);

USTRUCT(BlueprintType)
struct FCDCStringArray
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CDCStringArray")
	TArray<FString> Data;

	UPROPERTY(BlueprintReadOnly, Category="CDCStringArray")
	int32 ExtraData;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCDCStringArrayRep, FCDCStringArray, EventStringArray);

