// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Capture/FortCarriedObject.h"
#include "FortFlag.generated.h"

class UCapsuleComponent;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortFlag : public AFortCarriedObject
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Mesh", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> FlagMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Collision", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UCapsuleComponent> CollisionComp;

};

