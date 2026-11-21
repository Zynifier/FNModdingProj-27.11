// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayMontageCallbackProxy.h"
#include "PlayMoverMontageCallbackProxy.generated.h"

class UAnimMontage;
class UKinematicMoverComponent;
class UPlayMoverMontageCallbackProxy;

// Runtime object used as a proxy to an async blueprint task node that runs animation montages on Mover actors. This leverages 
// parent UPlayMontageCallbackProxy to perform animation, while adding an accompanying layered move to handle any root motion 
// from the montage.

UCLASS()
class MOVER_API UPlayMoverMontageCallbackProxy : public UPlayMontageCallbackProxy
{
	GENERATED_BODY()

public:
	// Called to perform the query internally

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true"))
	static UPlayMoverMontageCallbackProxy* CreateProxyObjectForPlayMoverMontage(UKinematicMoverComponent* InMoverComponent, UAnimMontage* MontageToPlay, float PlayRate = 1.000000f, float StartingPosition = 0.000000f, FName StartingSection = NAME_None);

protected:
	UFUNCTION()
	void OnMoverMontageEnded(FName IgnoredNotifyName);

};

