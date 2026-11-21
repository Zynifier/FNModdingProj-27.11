// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortPhysicsObjectInterface.generated.h"

class AActor;
class AController;

UINTERFACE(MinimalAPI)
class UFortPhysicsObjectInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortPhysicsObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, meta=(BlueprintProtected, DisplayName="Handle Custom Impulse From Damage"))
	bool HandleCustomImpulseFromDamage(const FVector ImpulseValue, const float Damage, const FGameplayTagContainer& DamageTags, const FHitResult& HitResult, AController* InstigatingController, AActor* DamageCauser, const FGameplayEffectContextHandle& EffectContext);

};

