// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "LiveEditObjectTest.generated.h"

class UObject;

USTRUCT()
struct FLiveEditObjectTestStruct
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool Bool;

	UPROPERTY()
	int8 Int8;

	UPROPERTY()
	int16 Int16;

	UPROPERTY()
	int32 Int32;

	UPROPERTY()
	int64 Int64;

	UPROPERTY()
	float Float;

	UPROPERTY()
	double Double;

	UPROPERTY()
	FString String;

	UPROPERTY()
	FText Text;

	UPROPERTY()
	FName Name;

	UPROPERTY()
	TObjectPtr<UObject> RawObjectPtr;

	UPROPERTY()
	TObjectPtr<UObject> ObjectPtr;

	UPROPERTY()
	FSoftObjectPath SoftObjectPath;

	UPROPERTY()
	FVector2D Struct;

	UPROPERTY()
	int32 FixedArray[4];

	UPROPERTY()
	TArray<int32> DynamicArray;

	UPROPERTY()
	TSet<int32> Set;

	UPROPERTY()
	TMap<int32, int32> Map;

};

UCLASS()
class ULiveEditObjectTestObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Int32[3];

	UPROPERTY()
	FLiveEditObjectTestStruct StructProperty;

};

