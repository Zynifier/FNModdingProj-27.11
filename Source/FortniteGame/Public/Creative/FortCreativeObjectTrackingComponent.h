// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortCreativeObjectTrackingComponent.generated.h"

UCLASS()
class UFortCreativeObjectTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnThermometerBetaEnabledChangedSignature, bool, bBetaEnabled);

private:
	UFUNCTION(Server, Reliable)
	void ServerSetPreviewLocation(bool bPreviewActive, const FVector& Location);

	UPROPERTY(Replicated)
	bool bUpdatePreviewLocation;

};

