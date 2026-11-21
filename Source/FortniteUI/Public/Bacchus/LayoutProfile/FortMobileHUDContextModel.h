// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Bacchus/LayoutProfile/FortMobileContextFilter.h"
#include "FortMobileHUDContextModel.generated.h"

class UPaperSprite;

UENUM(BlueprintType)
enum class EContextLayoutAccessLevel : uint8
{
	Editable = 0 UMETA(Tooltip="The layout will be present and editable by players in the HUD Layout Tool."),
	Hidden = 1 UMETA(Tootltip="The layout will be hidden from the HUD Layout Tool for players."),
};

USTRUCT()
struct FFortMobileHUDContextModelExtension
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Save", meta=(Categories="HUDLayout.ContextLayout"))
	FGameplayTag ContextLayoutTag;

	UPROPERTY(EditAnywhere, Category="HUDWidgets", meta=(Categories="MobileHUD"))
	FGameplayTagContainer UseableHUDWidgetTags;

};

UCLASS()
class UFortMobileHUDContextModel : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDContextModel")
	FText ContextLayoutName;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDContextModel")
	int32 DisplayOrderPriority;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDContextModel")
	bool bIsEditingContextByDefault;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDContextModel")
	TObjectPtr<UPaperSprite> ContextIcon;

	UPROPERTY(EditAnywhere, Category="Save", meta=(Categories="HUDLayout.ContextLayout"))
	FGameplayTag ContextLayoutSaveTag;

	UPROPERTY(EditAnywhere, Category="Filter")
	FFortMobileContextFilter ContextFilter;

	UPROPERTY(EditAnywhere, Category="HUDWidgets", meta=(Categories="MobileHUD"))
	FGameplayTagContainer UseableHUDWidgetTags;

	UPROPERTY(Transient)
	TArray<FFortMobileHUDContextModelExtension> Extensions;

	UPROPERTY(EditAnywhere, Category="HUD Layout Tool Player Access Level")
	EContextLayoutAccessLevel ContextLayoutAccessLevel;

};

