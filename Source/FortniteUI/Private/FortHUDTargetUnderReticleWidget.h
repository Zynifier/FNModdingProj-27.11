// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FortHUDTargetUnderReticleWidget.generated.h"

class AActor;
class IFortHUDTargetUnderReticleInterface;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHUDTargetUnderReticleWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleOnHUDTargetUnderReticle(TScriptInterface<IFortHUDTargetUnderReticleInterface>& NewTarget);

	UFUNCTION(BlueprintNativeEvent, Category="Target")
	void OnTargetChanged();

	UFUNCTION(BlueprintNativeEvent, Category="Target")
	void OnTargetDestroyed();

	UFUNCTION(BlueprintNativeEvent, Category="Target")
	void OnTargetDied();

	UFUNCTION(BlueprintNativeEvent, Category="Target")
	void OnTargetHealthChanged();

	UFUNCTION(BlueprintCallable, Category="Target")
	void Setup(bool bInKeepTargetUntilNewValidTarget, FGameplayTagContainer InTargetRequiredTags);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Target")
	TScriptInterface<IFortHUDTargetUnderReticleInterface> Target;

private:
	UFUNCTION(BlueprintCallable, Category="Target")
	void ClearTarget();

	UFUNCTION()
	void OnTargetActorDestroyed(AActor* DestroyedActor);

	UPROPERTY(EditInstanceOnly, Category="FortHUDTargetUnderReticleWidget")
	bool bKeepTargetUntilNewValidTarget;

	UPROPERTY(EditInstanceOnly, Category="FortHUDTargetUnderReticleWidget")
	FGameplayTagContainer TargetRequiredTags;

};

