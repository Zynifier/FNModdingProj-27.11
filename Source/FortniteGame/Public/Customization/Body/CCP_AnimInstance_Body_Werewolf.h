// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_Werewolf.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_Werewolf : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	FVector SlopeRootTrans;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	FRotator SlopeFootRot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	FRotator SimSpaceRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	FVector GravityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotUpL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotInrL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotOtrL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotUpR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotInrR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ThighRotOtrR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float BwdMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float RightMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float LeftMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float JumpingAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float IsNotCrouchRunning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float ParachuteAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	float SkydiveAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	bool bInComponentSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	bool bInComponentSpaceLastFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Werewolf|Native Properties")
	bool bLockedOnSimSpace;

	UPROPERTY(EditDefaultsOnly, Category="Werewolf|Magic Names")
	FName ThighLBoneName;

	UPROPERTY(EditDefaultsOnly, Category="Werewolf|Magic Names")
	FName ThighRBoneName;

	UPROPERTY(EditDefaultsOnly, Category="Werewolf|Magic Names")
	FName PelvisBoneName;

};

