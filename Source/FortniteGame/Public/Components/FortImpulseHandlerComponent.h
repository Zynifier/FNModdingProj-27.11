// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortImpulseHandlerComponent.generated.h"

class AActor;
class AController;
class UFortAthenaImpulseResponseSet;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FFortImpulseHandlerImpulseChangedEvent, const FVector&, ImpulsePoint, const FVector&, ImpulseMagnitude, const FGameplayTagContainer&, TagContainer, const FGameplayEffectContextHandle&, EffectContext, AController*, Instigator, AActor*, EffectCauser);

UCLASS(MinimalAPI, BlueprintType, meta=(BlueprintSpawnableComponent, ChildCannotTick))
class UFortImpulseHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FFortImpulseHandlerImpulseChangedEvent ImpulseChangedEvent;

private:
	UFUNCTION()
	void HandleImpulsed(const FVector& ImpulsePoint, const FVector& ImpulseValue, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& InEffectContext, AController* InEventInstigator, AActor* InImpulseCauser);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaImpulseResponseSet> ImpulseResponseSet;

};

