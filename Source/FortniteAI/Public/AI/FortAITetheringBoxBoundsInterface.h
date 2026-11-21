// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAITetheringBoxBoundsInterface.generated.h"

UINTERFACE(MinimalAPI)
class UFortAITetheringBoxBoundsInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAITetheringBoxBoundsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="AI")
	FVector GetTetheredBoxBoundsCenter();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="AI")
	float GetTetheredBoxBoundsEQSGridSize();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="AI")
	float GetTetheredBoxBoundsEQSSpaceBetween();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="AI")
	float GetTetheredBoxBoundsHeight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="AI")
	float GetTetheredBoxBoundsWidth();

};

