// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerGliderAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_SpringGlider.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortGliderAnimInstance.generated.h"

class AFortPlayerParachute;
class AFortPlayerPawn;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortGliderAnimInstance : public UFortBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetGliderFullyDeployed(bool bIsFullyDeployed = true);

protected:
	UFUNCTION(BlueprintCallable)
	void SetUseAltGliderCamera(bool bUseAltCamera);

	UFUNCTION(BlueprintPure)
	bool ShouldForceOpenGlider() const;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float DeltaTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	TObjectPtr<AFortPlayerParachute> OwnerGlider;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	TObjectPtr<AFortPlayerPawn> OwnerFortPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_Skydiving SkydivingState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_SpringGlider SpringGliderInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerGliderAnimAsset CurrentGliderAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	bool bIsAccelerating2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	bool bForceOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	bool bForceOpen_SkipInto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortGliderAnimInstance")
	float Glider_BaseBS_PlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortGliderAnimInstance")
	float Glider_IntoBS_PlayRate;

};

