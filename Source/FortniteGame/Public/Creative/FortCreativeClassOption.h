// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortUserOptionDefinitions.h"
#include "FortCreativeClassOption.generated.h"

enum class ECreativeClassType : uint8;

UENUM(BlueprintType)
enum class ECreativeClassType : uint8
{
	/** Use the specified class slot value */
	ClassSlot = 0,
	NoClass = 1,
	All = 2,
	Any = 3,
};

USTRUCT(BlueprintType, Atomic)
struct FCreativeClassOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Creative|ClassOption")
	ECreativeClassType ClassType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Creative|ClassOption")
	int32 ClassSlot;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionClassTypeEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	ECreativeClassType Value;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionClassSlotMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FCreativeClassOption DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MinClassSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MaxClassSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText ClassSlotDisplayPattern;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	TArray<ECreativeClassType> ClassTypesToShow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	TArray<ECreativeClassType> ClassTypesToHide;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	TArray<FUserOptionDefinitionClassTypeEntry> ClassTypeEntries;

};

UCLASS(meta=(ScriptName="CreativeClassOptionLibrary"))
class UCreativeClassOptionBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Creative|ClassOption", meta=(ScriptMethod))
	static uint8 ConvertToClassSlotIndex(const FCreativeClassOption& ClassOption);

	UFUNCTION(BlueprintPure, Category="Creative|ClassOption", meta=(ScriptMethod))
	static int32 GetLegacyClassIndex(const FCreativeClassOption& ClassOption);

	UFUNCTION(BlueprintPure, Category="Creative|ClassOption", meta=(ScriptMethod))
	static bool IsClassType(const FCreativeClassOption& ClassOption, const ECreativeClassType ClassType);

	UFUNCTION(BlueprintPure, Category="Creative|ClassOption")
	static FCreativeClassOption MakeFromLegacyClassIndex(const int32 LegacyClassIndex);

	UFUNCTION(BlueprintCallable, Category="Creative|ClassOption", meta=(ScriptMethod))
	static void SetLegacyClassIndex(UPARAM(ref) FCreativeClassOption& ClassOption, const int32 LegacyClassIndex);

};

