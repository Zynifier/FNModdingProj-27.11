// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "UIManager/FortActivatablePanel.h"
#include "CampaignTopBar.generated.h"

class UDataTable;
class UFortPhoenixSeasonDisplayInfo;
class UMaterialInterface;
class URestrictedCountryRatingIcons;

USTRUCT(BlueprintType)
struct FORTNITEUI_API FFortPhoenixSeasonDisplayInfoMapRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhoenixSeasonDisplayInfoMapRow")
	FString EventFlagName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhoenixSeasonDisplayInfoMapRow")
	TObjectPtr<UFortPhoenixSeasonDisplayInfo> DisplayInfo;

};

UCLASS(meta=(DisableNativeTick))
class UCampaignTopBar : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetActiveInvitesCount(int32 NewActiveInvitesCount);

	UFUNCTION(BlueprintImplementableEvent)
	void SetOnlineFriendsCount(int32 NewOnlineFriendsCount);

	UFUNCTION(BlueprintPure)
	UFortPhoenixSeasonDisplayInfo* TryGetCurrentPhoenixSeasonDisplayInfo() const;

	UPROPERTY(EditAnywhere, Category="CampaignTopBar")
	TObjectPtr<UDataTable> PhoenixSeasonDisplayInfoMap;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URestrictedCountryRatingIcons> RatingIcons_RatingIcons;

};

UCLASS()
class FORTNITEUI_API UFortPhoenixSeasonDisplayInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhoenixSeasonDisplayInfo")
	TObjectPtr<UMaterialInterface> CenterBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhoenixSeasonDisplayInfo")
	TObjectPtr<UMaterialInterface> LeftBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhoenixSeasonDisplayInfo")
	TObjectPtr<UMaterialInterface> RightBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhoenixSeasonDisplayInfo")
	FLinearColor PowerBackgroundColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhoenixSeasonDisplayInfo")
	FLinearColor LevelTextColor;

};

