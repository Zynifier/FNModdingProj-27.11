// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonUserWidget.h"
#include "BattlePassLeaderboardListEntry.generated.h"

class UCommonTextBlock;
class URichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassLeaderboardListEntry : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEntryInitialized(int32 Rank, bool bIsLocalPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateEntryVisibility();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLeaderboardListEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_DisplayName;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLeaderboardListEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassLeaderboardListEntry", meta=(AllowPrivateAccess="TRUE"))
	bool bIsEntry;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Rank", EditCondition="bIsEntry"))
	int32 DesignTime_Rank;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Display Name", EditCondition="bIsEntry"))
	FString DesignTime_DisplayName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Level", EditCondition="bIsEntry"))
	int32 DesignTime_Level;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Is Local Player", EditCondition="bIsEntry"))
	bool bDesignTime_IsLocalPlayer;
#endif

};

