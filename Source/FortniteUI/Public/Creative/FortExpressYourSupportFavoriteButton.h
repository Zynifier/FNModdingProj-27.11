// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortExpressYourSupportToggleButton.h"
#include "FortExpressYourSupportFavoriteButton.generated.h"

class UFortGameActivity;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortExpressYourSupportFavoriteButton : public UFortExpressYourSupportToggleButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Refresh();

	UFUNCTION(BlueprintCallable)
	void SetActivity(UFortGameActivity* NewActivity);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortExpressYourSupportFavoriteButton")
	bool bEditorOverrideEnable;
#endif

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortExpressYourSupportFavoriteButton", meta=(ExposeOnSpawn))
	TObjectPtr<UFortGameActivity> Activity;

};

