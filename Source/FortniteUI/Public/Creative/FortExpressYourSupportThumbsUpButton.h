// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortExpressYourSupportToggleButton.h"
#include "FortExpressYourSupportThumbsUpButton.generated.h"

class AFortPlayerPawn;
class UFortSidebarOnboardTooltipWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortExpressYourSupportThumbsUpButton : public UFortExpressYourSupportToggleButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FString GetCreatorName() const;

	UFUNCTION(BlueprintCallable)
	void Refresh();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortExpressYourSupportThumbsUpButton")
	bool bEditorOverrideEnable;
#endif

protected:
	UFUNCTION()
	void TrySendLikeAnalytic(AFortPlayerPawn* Pawn);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> SidebarOnboardingLikeIsland;

	UPROPERTY(EditAnywhere, Category="FortExpressYourSupportThumbsUpButton")
	FString SourceName;

};

