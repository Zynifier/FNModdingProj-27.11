// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortPersistentProp.generated.h"

class AFortPawn;
class UAthenaCosmeticItemDefinition;

UCLASS()
class AFortPersistentProp : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DestroyProp(bool bShouldInstantDestroy);

	UFUNCTION(BlueprintPure)
	AFortPawn* GetFortPawnOwner() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDetach();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Lifetime")
	float BaseLifetime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Lifetime")
	float RemainingLifetime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Customization")
	bool bApplyCosmeticVariants;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Customization")
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> VariantItemDefinition;

};

