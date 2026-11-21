// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortEventPlayerStatProfileSelector.generated.h"

class UAthenaStatsScreenBase;
class UCommonListView;
class UCommonTextBlock;
class UFortEventLeaderboardEntryData;
class UFortEventPlayerStatProfileSelectorEntryData;
class UFortFlagImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventPlayerStatProfileSelector : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void SetProfilesByLeaderboardData(const UFortEventLeaderboardEntryData* DataForDisplay);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPlayerStatProfileSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ProfileList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPlayerStatProfileSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> HoveredName;

	UPROPERTY(EditAnywhere, Category="FortEventPlayerStatProfileSelector")
	TSubclassOf<UAthenaStatsScreenBase> StatsScreenClass;

};

UCLASS(Abstract)
class UFortEventPlayerStatProfileSelectorEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPlayerStatProfileSelectorEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPlayerStatProfileSelectorEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> FlagImage;

	UPROPERTY(Transient)
	TObjectPtr<UFortEventPlayerStatProfileSelectorEntryData> ProfileData;

};

UCLASS(BlueprintType)
class UFortEventPlayerStatProfileSelectorEntryData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortEventPlayerStatProfileSelectorEntryData")
	FString AccountId;

	UPROPERTY(BlueprintReadOnly, Category="FortEventPlayerStatProfileSelectorEntryData")
	FString DisplayName;

};

