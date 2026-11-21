// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_HighTowerDateBody.generated.h"

class UAnimMontage;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_HighTowerDateBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	float SkydiveFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	float CrouchFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	bool bThrone;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	float ThroneFloat;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	float ThroneFloatINV;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	float DateGliderDeployFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	float FrontEndPosingFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	float JubileeFloat;

	UPROPERTY(EditDefaultsOnly, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	TArray<TSoftObjectPtr<UAnimMontage>> ThroneAnimations;

	UPROPERTY(EditDefaultsOnly, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	TSoftObjectPtr<UAnimMontage> JubileeAnimation;

	UPROPERTY(EditDefaultsOnly, Category="CustomCharacterPartAnimInstance_HighTowerDateBody")
	TSoftObjectPtr<UAnimMontage> FrontEndPoseAnimation;

};

