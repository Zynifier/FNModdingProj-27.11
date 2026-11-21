// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortToastWidget.generated.h"

class UFortUINotification;

UCLASS(Abstract, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortToastWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, meta=(BlueprintProtected="true"))
	float GetDisplayTime(bool& bOutDisplayTimeOverridden) const;

	UFUNCTION(BlueprintCallable)
	void NotifyCloseAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNotificationSet(UFortUINotification* Notification);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNotificationUpdated(UFortUINotification* Notification);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayCloseAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayOpenAnimation();

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortToastWidget")
	TObjectPtr<UFortUINotification> CachedNotification;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortToastWidget", meta=(ClampMin="1.000000"))
	float DefaultDisplayTime;

};

