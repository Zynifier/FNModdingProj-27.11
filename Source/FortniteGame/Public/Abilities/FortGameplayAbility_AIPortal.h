// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility_Action.h"
#include "FortGameplayAbility_AIPortal.generated.h"

class ABuildingSMActor;

UCLASS()
class UFortGameplayAbility_AIPortal : public UFortGameplayAbility_Action
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Ability|AI")
	ABuildingSMActor* GetPortalBuilding() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Ability|AI")
	FVector GetPortalInPoint() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Ability|AI")
	FVector GetPortalOutPoint() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Ability|AI")
	bool HasPortalOutPoint() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ability|AI")
	void ModifyCollisions();

protected:
	UPROPERTY(BlueprintReadOnly, Category="Portal")
	FVector PortalDirection;

	UPROPERTY(EditAnywhere, Category="Portal")
	float PortalLifespan;

	UPROPERTY(BlueprintReadOnly, Category="Portal")
	TArray<TObjectPtr<ABuildingSMActor>> NoCollisionBuildings;

	UPROPERTY(EditDefaultsOnly, Category="Portal")
	float SlopeOffset;

	UPROPERTY(EditDefaultsOnly, Category="Portal")
	bool bConsiderFences;

	UPROPERTY(EditDefaultsOnly, Category="Portal")
	bool bAdjustForCapsuleSize;

	UPROPERTY(EditDefaultsOnly, Category="Portal")
	bool bCapsuleTraceForSlope;

};

