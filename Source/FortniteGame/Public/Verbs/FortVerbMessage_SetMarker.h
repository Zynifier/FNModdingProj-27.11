// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Markers/FortWorldMarkerTypeEnum.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_SetMarker.generated.h"

USTRUCT()
struct FFortVerbMessage_SetMarker : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SetMarker")
	FSubjectTagsPair MarkedActor;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SetMarker")
	int32 ItemCount;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SetMarker")
	EFortWorldMarkerType MarkerType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SetMarker")
	FVector BasePosition;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SetMarker")
	FGameplayTagContainer MarkerTags;

};

