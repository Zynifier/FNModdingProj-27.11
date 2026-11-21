// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Math/MathFwd.h"
#include "FortAnimNotifyState_ToySpawn.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Spawn Cosmetic Toy"))
class UFortAnimNotifyState_ToySpawn : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	FVector LocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	FRotator RotationOffset;

	UPROPERTY(EditAnywhere, Category="AnimNotify")
	int32 PropId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	bool bRepositionOnSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify", meta=(EditCondition="bRepositionOnSpawn"))
	FTransform ComponentSpaceSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	bool bRepositionOnLaunch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify", meta=(EditCondition="bRepositionOnLaunch"))
	FTransform ComponentSpaceLaunchPoint;

};

