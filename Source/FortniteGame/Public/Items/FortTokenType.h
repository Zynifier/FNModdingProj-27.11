// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortTokenType.generated.h"

class AFortItemPreviewActor;
class AFortScriptedAction;

UCLASS(MinimalAPI)
class UFortTokenType : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortTokenType")
	TSoftClassPtr<AFortScriptedAction> ScriptedAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Brush", meta=(DisplayName="Node Colour", sRGB="true"))
	FSlateColor NodeTintColour;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTokenType")
	bool bPercentageRepresentation;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTokenType")
	EItemProfileType ProfileType;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortTokenType")
	TSoftClassPtr<AFortItemPreviewActor> ItemPreviewActorClass;

};

