// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction_PostFrontendFlowActions.h"
#include "FortUIGameFeatureAction_AttemptKoalaModal.generated.h"

class UKoalaGraphicsModal;

UCLASS(meta=(DisplayName="Attempt Koala Modal"))
class KOALAUI_API UFortUIGameFeatureAction_AttemptKoalaModal : public UFortUIGameFeatureAction_PostFrontendFlowActions
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_AttemptKoalaModal")
	TSoftClassPtr<UKoalaGraphicsModal> KoalaGraphicsModalClass;

};

