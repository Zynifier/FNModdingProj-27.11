// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "RemoteControlledPawnExpirationWidget.generated.h"

class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class URemoteControlledPawnExpirationWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPawnChanged();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> ExpirationProgressImage;

};

