// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "ContextualAnimTypes.h"
#include "FortAbilityTask_PlayContextualAnimAndWait.generated.h"

class UContextualAnimSceneActorComponent;
class UContextualAnimSceneAsset;
class UFortAbilityTask_PlayContextualAnimAndWait;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FContextualAnimWaitSimpleDelegate);

UCLASS()
class UFortAbilityTask_PlayContextualAnimAndWait : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", DisplayName="PlayContextualAnimAndWait", HidePin="OwningAbility"))
	static UFortAbilityTask_PlayContextualAnimAndWait* CreatePlayContextualAnimAndWaitProxy(UGameplayAbility* OwningAbility, FName TaskInstanceName, const UContextualAnimSceneAsset* SceneAsset, const TMap<FName, FContextualAnimSceneBindingContext>& Params);

	UFUNCTION()
	void OnGameplayAbilityCancelled();

	UFUNCTION()
	void OnLeftContextualAnimScene(UContextualAnimSceneActorComponent* SceneActorComponent);

	UPROPERTY(BlueprintAssignable)
	FContextualAnimWaitSimpleDelegate OnCompleted;

	UPROPERTY(BlueprintAssignable)
	FContextualAnimWaitSimpleDelegate OnInterrupted;

	UPROPERTY(BlueprintAssignable)
	FContextualAnimWaitSimpleDelegate OnCancelled;

protected:
	UPROPERTY()
	TObjectPtr<UContextualAnimSceneAsset> SceneAssetToPlay;

	UPROPERTY()
	TMap<FName, FContextualAnimSceneBindingContext> ParamsToUse;

};

