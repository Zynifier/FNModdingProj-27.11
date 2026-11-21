// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortLOSComponent.generated.h"

class AFortPlayerController;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHasBeenFoundDelSignature, AFortPlayerController*, PlayerController);

UCLASS(BlueprintType, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UFortLOSComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visibility")
	float LOSMaxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visibility", meta=(ClampMax="180", ClampMin="10"))
	float FOVInDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visibility", meta=(ClampMin="0.1"))
	float TimeBetweenChecks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visibility")
	bool bStopAfterHasBeenFound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visibility")
	bool bDistanceCheckOnly;

	UPROPERTY(BlueprintAssignable)
	FOnHasBeenFoundDelSignature OnHasBeenFound;

protected:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="Visibility")
	bool bHasBeenFound;

};

