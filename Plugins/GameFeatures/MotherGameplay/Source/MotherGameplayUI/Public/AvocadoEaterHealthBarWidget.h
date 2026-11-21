// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "AvocadoEaterHealthBarWidget.generated.h"

class UObject;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAvocadoEaterHealthBarWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnParasiteAttached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnParasiteDetached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetMarkerPosition(float MarkerPosition);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetDamaged();

private:
	UPROPERTY(EditDefaultsOnly, Category="UI")
	FEventMessageTag AttachedMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> AttachedMessageType;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FEventMessageTag DetachedMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> DetachedMessageType;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FEventMessageTag SetMarkerPositionMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> SetMarkerPositionMessageType;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FName SetMarkerPositionMessagePropertyName;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FEventMessageTag TargetDamagedMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> TargetDamagedMessageType;

};

