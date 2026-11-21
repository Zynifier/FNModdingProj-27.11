// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortDamageNumbersActor.h"
#include "FortAthenaMutator_OverrideDamageNumberInfo.generated.h"

class AActor;
class APawn;
enum class EFortMutatorReturnValue : uint8;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_OverrideDamageNumberInfo : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="DamageNumberModifyComponent")
	EFortMutatorReturnValue ModifyDamageNumberInfo(UPARAM(ref) FFortDamageNumberInfo& InOutDamageNumberInfo, const AActor* DamagedActor, const APawn* DamageCauser, const FVector& HitPosition) const;

};

