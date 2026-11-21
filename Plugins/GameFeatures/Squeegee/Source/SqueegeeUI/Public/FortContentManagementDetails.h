// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Plugin/Squeegee/FortSqueegeeTypes.h"
#include "FortContentManagementDetails.generated.h"

class UFortContentGateRatingWidget;
class UFortGameActivity;
class UTexture;

UCLASS()
class SQUEEGEEUI_API UFortContentManagementDetails : public UFortSqueegeeWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowActivityData(const FText& ActivityDisplayName, const FText& ActivityDescription, const FString& CreatorName, const FText& LinkCode, const bool IsCreative, const FDateTime& UnlockTime, UFortGameActivity* GameActivity);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowWeaponData();

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortContentGateRatingWidget> ContentGateRatingWidget;

};

