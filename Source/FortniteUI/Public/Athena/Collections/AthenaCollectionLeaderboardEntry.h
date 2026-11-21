// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionOverlayEntry.h"
#include "AthenaCollectionLeaderboardEntry.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortSocialAvatarIcon;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionLeaderboardEntry : public UAthenaCollectionOverlayEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Leaderboard Entry Initialized"))
	void BP_OnLeaderboardEntryInitialized(bool bIsLocalPlayer);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Leaderboard Entry Reset"))
	void BP_OnLeaderboardEntryReset();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Placement Set"))
	void BP_OnPlacementSet(int32 Placement);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Value Set"))
	void BP_OnValueSet(float Value);

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Placement"))
	int32 DesignTime_Placement;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Display Name"))
	FString DesignTime_DisplayName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="-1.000000", DisplayName="Value"))
	float DesignTime_Value;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Is Local Player"))
	bool bDesignTime_IsLocalPlayer;
#endif

	UPROPERTY(EditAnywhere, Category="Text")
	FText ValueTextFormat;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionLeaderboardEntry", meta=(ClampMin="0"))
	int32 ValueMinimumFractionalDigits;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionLeaderboardEntry", meta=(ClampMin="0"))
	int32 ValueMaximumFractionalDigits;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionLeaderboardEntry")
	bool bValueIsFloat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Placement;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Value;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> AvatarIcon;

};

