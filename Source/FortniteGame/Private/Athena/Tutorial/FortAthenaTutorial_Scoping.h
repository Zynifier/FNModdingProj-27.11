// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "Athena/Tutorial/FortAthenaTutorialTargetInfo.h"
#include "FortAthenaTutorial_Scoping.generated.h"

class AActor;
class UFortItemDefinition;

UCLASS()
class AFortAthenaTutorial_Scoping : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scoping Tutorial Actors")
	TArray<FFortAthenaTutorial_TargetInfo> ShootTargets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scoping Tutorial Items")
	TObjectPtr<UFortItemDefinition> GunToEquipItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scoping Tutorial Actors")
	TObjectPtr<AActor> ScopingCameraPoint;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Scoping Targets")
	void OnScopingTargetsActivated();

private:
	UFUNCTION()
	void OnTargetDestroyed(int32 TargetIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float ScopingCameraInSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float ScopingCameraOutSpeed;

};

