// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Abilities/FortAbilityTypes.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemDefinitionItemModifierInterface.h"
#include "STW/Items/FortCosmeticModification.h"
#include "FortAlterationItemDefinition.generated.h"

class UFortAbilitySet;
class UNiagaraSystem;
class UParticleSystem;

UCLASS()
class UFortAlterationFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Fort Alteration")
	static UNiagaraSystem* GetAlterationImpactNiagaraPhysicalSurfaceEffects(EPhysicalSurface HitSurface, const FFortCosmeticModification& CosmeticMod);

	UFUNCTION(BlueprintPure, Category="Fort Alteration")
	static UParticleSystem* GetAlterationImpactPhysicalSurfaceEffects(EPhysicalSurface HitSurface, const FFortCosmeticModification& CosmeticMod);

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAlterationItemDefinition : public UFortAccountItemDefinition, public IFortItemDefinitionItemModifierInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortAlteration::Type GetAlterationType() const;

private:
	UPROPERTY(EditAnywhere, Category="AlterationDefinition")
	TEnumAsByte<EFortAlteration::Type> AlterationType;

	UPROPERTY(EditAnywhere, Category="AlterationCosmetic")
	FFortCosmeticModification DefaultCosmetic;

	UPROPERTY(EditAnywhere, Category="AlterationCosmetic")
	TArray<FFortConditionalCosmeticModification> ConditionalCosmetics;

	UPROPERTY(EditAnywhere, Category="AlterationGameplay")
	TArray<FFortConditionalIncludeTags> AdditionalGameplayTags;

	UPROPERTY(EditAnywhere, Category="AlterationGameplay", meta=(AssetBundles="ItemsInInventoryInZone"))
	TSoftObjectPtr<UFortAbilitySet> AlterationAbilitySet;

	UPROPERTY(EditAnywhere, Category="Conversion")
	TArray<FFortItemQuantityPair> AdditionalRespecCosts;

};

