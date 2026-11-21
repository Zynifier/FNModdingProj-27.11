// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "Slate/WidgetTransform.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "UObject/PrimaryAssetId.h"
#include "FrontEnd/FrontEndTypes.h"
#include "FortQuestMapPage.generated.h"

class UDataTable;
class UFortEventQuestMapDataAsset;
class UFortItemDefinition;
class UFortQuestItemDefinition;
class UFortQuestMapDataAsset;
class UMaterialInterface;
class USoundBase;
class UUserWidget;

UENUM(BlueprintType)
enum class ECosmeticType : uint8
{
	Image = 0,
	Widget = 1,
};

UENUM(BlueprintType)
enum class EFortQuestMapNodeLabelPosition : uint8
{
	Top = 0,
	Bottom = 1,
};

UENUM(BlueprintType)
enum class EFortQuestMapNodeType : uint8
{
	MandatoryQuest = 0,
	SideQuest = 1,
};

USTRUCT(BlueprintType)
struct FFortQuestMapCosmetic
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapCosmetic")
	ECosmeticType CosmeticType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapCosmetic")
	FSlateBrush CosmeticBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapCosmetic")
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapCosmetic")
	TSubclassOf<UUserWidget> WidgetClass_Legacy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapCosmetic")
	TArray<TObjectPtr<UFortItemDefinition>> CosmeticDataList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapCosmetic")
	FVector2D CosmeticPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapCosmetic")
	FWidgetTransform CosmeticTransform;

};

USTRUCT(BlueprintType)
struct FFortQuestMapNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapNode")
	EFortQuestMapNodeType NodeType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapNode")
	EFortQuestMapNodeLabelPosition LabelPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapNode")
	bool UseHighContrastMode;

private:
	UPROPERTY(VisibleAnywhere, Category="FortQuestMapNode")
	FPrimaryAssetId QuestItemDefinitionId;

	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition> QuestItemDefinition;

};

USTRUCT(BlueprintType)
struct FFortQuestMapPage : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	FText PageTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	int32 PageIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	int32 ChapterPageCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	FString QuestEventFlag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	EFrontEndCamera CameraMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	TSubclassOf<UUserWidget> QuestNodeLayout_Legacy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	TSubclassOf<UUserWidget> QuestNodeLayout_Leto;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPage")
	TArray<FFortQuestMapNode> QuestList;

};

USTRUCT(BlueprintType)
struct FFortQuestMapPageCosmetics : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPageCosmetics")
	bool bUseNodeArrowColorOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPageCosmetics")
	FSlateColor NodeArrowColorOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapPageCosmetics")
	TArray<FFortQuestMapCosmetic> CosmeticList;

};

UCLASS()
class UFortQuestMapDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapDataAsset")
	TObjectPtr<UDataTable> QuestData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapDataAsset")
	TObjectPtr<UDataTable> CosmeticData;

};

UCLASS()
class UFortEventQuestMapDataAsset : public UFortQuestMapDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	FText EventCalloutTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset", meta=(MultiLine="true"))
	FText EventCalloutDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	TObjectPtr<UMaterialInterface> EventCalloutImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	TObjectPtr<USoundBase> EventCalloutOverrideSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	FSlateColor EventArrowColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	FSlateColor EventArrowShadowColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	FString EventCalloutQuestFlag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	TObjectPtr<UFortQuestItemDefinition> RequiredCompletedQuest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventQuestMapDataAsset")
	bool bOnlyDisplayIfRequiredCompletedQuest;

};

UCLASS()
class UFortQuestMapData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestMapData")
	TObjectPtr<UFortQuestMapDataAsset> CampaignQuestMapDataAsset;

	UPROPERTY(EditAnywhere, Category="FortQuestMapData")
	TArray<TObjectPtr<UFortEventQuestMapDataAsset>> EventQuestMapDataAssetList;

};

