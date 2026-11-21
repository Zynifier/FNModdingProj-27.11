// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltCountdownWidgetBase.generated.h"

UCLASS()
class UCobaltCountdownWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCountdownText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Countdown")
	FText CountdownMessage;

	UPROPERTY(BlueprintReadOnly, Category="Countdown")
	float CountdownTime;

private:
	UFUNCTION()
	void HandleTeleportComplete();

};

