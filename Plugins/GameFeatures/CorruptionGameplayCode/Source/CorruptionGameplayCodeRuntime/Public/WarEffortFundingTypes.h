// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MeshNetworkSubsystem.h"
#include "WarEffortFundingTypes.generated.h"

UENUM(BlueprintType)
enum EWarEffortFundingStationType
{
	Final = 0 UMETA(DisplayName="Final"),
	// The mech

	Tower = 1 UMETA(DisplayName="Tower"),
	Choice = 2 UMETA(DisplayName="Choice"),
};

USTRUCT(BlueprintType)
struct FWarEffortFundingOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="WarEffortFundingOptionData")
	FGameplayTag OptionTag;

	UPROPERTY(BlueprintReadWrite, Category="WarEffortFundingOptionData")
	int64 CurrentFundingAmount;

};

USTRUCT(BlueprintType)
struct FWarEffortFundingChoiceData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="WarEffortFundingChoiceData")
	FWarEffortFundingOptionData Option1;

	UPROPERTY(BlueprintReadWrite, Category="WarEffortFundingChoiceData")
	FWarEffortFundingOptionData Option2;

	UPROPERTY(BlueprintReadWrite, Category="WarEffortFundingChoiceData")
	int64 TargetFundingAmount;

};

USTRUCT(BlueprintType)
struct FWarEffortIndexedFundingData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="WarEffortIndexedFundingData")
	TArray<int64> CurrentFundingArray;

	UPROPERTY(BlueprintReadWrite, Category="WarEffortIndexedFundingData")
	int64 FinalFundingAmount;

	UPROPERTY(BlueprintReadWrite, Category="WarEffortIndexedFundingData")
	int64 TowerFundingAmount;

};

USTRUCT(BlueprintType)
struct FWarEffortFundingMetadata : public FMeshMetaDataStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="WarEffortFundingMetadata")
	FWarEffortIndexedFundingData IndexedFundingData;

	UPROPERTY(BlueprintReadWrite, Category="WarEffortFundingMetadata")
	TArray<FWarEffortFundingChoiceData> FundingChoices;

};

UCLASS()
class UWarEffortFundingLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="War Effort")
	static int32 AdjustDonation(int32 DonationAmount, EWarEffortFundingStationType StationType);

	UFUNCTION(BlueprintPure, Category="War Effort")
	static bool DoesChoiceHaveWinner(const FWarEffortFundingMetadata& Metadata, int32 ChoiceIndex);

	UFUNCTION(BlueprintPure, Category="War Effort")
	static float GetIndexFundedPercent(const FWarEffortFundingMetadata& Metadata, int32 Index, EWarEffortFundingStationType StationType);

	UFUNCTION(BlueprintPure, Category="War Effort")
	static bool IsIndexFunded(const FWarEffortFundingMetadata& Metadata, int32 Index, EWarEffortFundingStationType StationType);

	UFUNCTION(BlueprintPure, Category="War Effort")
	static bool IsOption1ChoiceWinner(const FWarEffortFundingMetadata& Metadata, int32 ChoiceIndex);

	UFUNCTION(BlueprintPure, Category="War Effort")
	static bool IsOption2ChoiceWinner(const FWarEffortFundingMetadata& Metadata, int32 ChoiceIndex);

	UFUNCTION(BlueprintPure, Category="War Effort")
	static FString WriteTextToBuffer(const FText& Text);

};

