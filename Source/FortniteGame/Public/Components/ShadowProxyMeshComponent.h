// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/HitResult.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ShadowProxyMeshComponent.generated.h"

class AActor;
class AFortPawn;
class UMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Trigger"))
class UShadowProxyMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool DoesOwnerUseDynamicDestruction() const;

	UFUNCTION(BlueprintCallable)
	void EditorConstruct();

	UFUNCTION()
	void HandleOwnerDiedClient(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintPure)
	bool IsProxyEnabled(bool bCheckHealth) const;

	UFUNCTION(BlueprintCallable)
	void SetForceShadowDisabled(bool bDisable);

	UFUNCTION(BlueprintCallable)
	void SetShadowSettings(bool bCheckHealth);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shadow Proxy")
	bool bForceParentShadowOnWhenDisabled;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMeshComponent> ParentComponent;

	UPROPERTY(EditDefaultsOnly, Category="Default", meta=(MultiLine="true"))
	bool bForceShadowDisabled;

};

