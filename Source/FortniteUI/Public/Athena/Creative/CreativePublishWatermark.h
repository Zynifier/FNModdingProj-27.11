// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "Creative/FortCreativeTypes.h"
#include "FortHUDElementWidget.h"
#include "CreativePublishWatermark.generated.h"

class AFortVolume;
class UCommonTextBlock;
enum class ECreativePublishedIslandCodeDisplay : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePublishWatermark : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	bool IsModerator() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsPlaytestLinkChanged(const bool bIsPlaytestLink);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPublishedIslandCodeDisplayChanged(const ECreativePublishedIslandCodeDisplay PublishedIslandCodeDisplay);

private:
	UFUNCTION()
	void HandleCreativePlotLinkedVolumeChanged(AFortVolume* CreativeLinkedVolume);

	UFUNCTION()
	void HandleLinkDataQueryComplete(bool bSuccess, const FString& ErrorMessage, const FCreativeLoadedLinkData& LinkData);

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativePublishWatermark", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreatorName;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativePublishWatermark", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Mnemonic;

	UPROPERTY(EditDefaultsOnly, Category="CreativePublishWatermark")
	FText MnemonicVersionFormat;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Design Time", meta=(AllowPrivateAccess, DisplayName="Apply Design Time Values"))
	bool bDesignTime_ApplyDesignTimeValues;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Published Island Code Display", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	ECreativePublishedIslandCodeDisplay DesignTime_PublishedIslandCodeDisplay;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Creator Name", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	FString DesignTime_CreatorName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Mnemonic", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	FString DesignTime_Mnemonic;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="-1", DisplayName="Version", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	int32 DesignTime_Version;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="-1", DisplayName="Is Moderator", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	bool bDesignTime_IsModerator;
#endif

};

