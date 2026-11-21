// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaQuickChatActiveEntry.h"
#include "Building/BuildingTypes.h"
#include "FortPickerData.generated.h"

class UAthenaQuickChatBank;
class UObject;
class UTexture2D;

USTRUCT(BlueprintType)
struct FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RadialOptionData")
	FText Label;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RadialOptionData")
	FSlateBrush Brush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RadialOptionData")
	TSoftObjectPtr<UTexture2D> SoftIcon;

};

USTRUCT(BlueprintType)
struct FBuildingCategoryOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingCategoryOptionData")
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

};

USTRUCT(BlueprintType)
struct FBuildingOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingOptionData")
	FString ClassSuffix;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingOptionData")
	bool ClassMirrored;

};

USTRUCT(BlueprintType)
struct FChatOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ChatOptionData")
	FText ChatText;

};

USTRUCT(BlueprintType)
struct FEmoteOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EmoteOptionData")
	FName EmoteCommand;

};

USTRUCT(BlueprintType)
struct FItemCategoryOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemCategoryOptionData")
	FString TemplatePrefix;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemCategoryOptionData")
	TEnumAsByte<EBuildingAttachmentType> BuildingAttachmentType;

};

USTRUCT()
struct FItemDefOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDefOptionData")
	TObjectPtr<UObject> ItemDef;

};

USTRUCT(BlueprintType)
struct FMapNoteOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MapNoteOptionData")
	FText MapNoteText;

};

USTRUCT(BlueprintType)
struct FSquadChatOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SquadChatOptionData")
	FText ChatText;

};

USTRUCT()
struct FSquadQuickChatOptionData : public FRadialOptionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SquadQuickChatOptionData")
	FAthenaQuickChatActiveEntry ChatEntry;

	UPROPERTY()
	bool bEnabled;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortPickerData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingPicker")
	TArray<FBuildingCategoryOptionData> BuildingCategories;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingPicker")
	TArray<FBuildingOptionData> WallOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingPicker")
	TArray<FBuildingOptionData> FloorOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingPicker")
	TArray<FBuildingOptionData> StairOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingPicker")
	TArray<FBuildingOptionData> RoofOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TrapPicker")
	TArray<FItemCategoryOptionData> TrapCategories;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponPicker")
	TArray<FItemCategoryOptionData> WeaponCategories;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SocialPicker")
	TArray<FRadialOptionData> SocialCategories;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SocialPicker")
	TArray<FChatOptionData> ChatOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaChat")
	TArray<TObjectPtr<UAthenaQuickChatBank>> SquadChatOptionBanks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SocialPicker")
	TArray<FMapNoteOptionData> MapNoteOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SocialPicker")
	TArray<FEmoteOptionData> EmoteOptions;

};

