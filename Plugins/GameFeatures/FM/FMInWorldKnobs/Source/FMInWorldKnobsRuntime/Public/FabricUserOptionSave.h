// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InstancedStruct.h"
#include "FabricUserOptionSave.generated.h"

USTRUCT(BlueprintType)
struct FFabricUserOptionPreset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionPreset")
	FString UserOption;

	UPROPERTY(EditDefaultsOnly, Category="FabricUserOptionPreset", meta=(BaseStruct="/Script/FMInWorldKnobsRuntime.FabricUserOptionValue", ExcludeBaseStruct))
	FInstancedStruct UserOptionValue;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionPresetCollection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FabricUserOptionPresetCollection")
	TArray<FFabricUserOptionPreset> UserOptionPresets;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionSavedValue
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	FString Key;

	UPROPERTY(SaveGame)
	FString Value;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionSaveData
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	TArray<FFabricUserOptionSavedValue> SavedUserOptions;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionValue
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFabricUserOptionValueBool : public FFabricUserOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionValueBool")
	bool Value;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionValueEnum : public FFabricUserOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionValueEnum")
	FString Value;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionValueFloat : public FFabricUserOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionValueFloat")
	float Value;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionValueInt : public FFabricUserOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionValueInt")
	int32 Value;

};

USTRUCT(BlueprintType)
struct FFabricUserOptionValueString : public FFabricUserOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionValueString")
	FString Value;

};

UCLASS(BlueprintType)
class UFabricUserOptionPresetAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionPresetAsset")
	FFabricUserOptionPresetCollection UserOptionPreset;

};

