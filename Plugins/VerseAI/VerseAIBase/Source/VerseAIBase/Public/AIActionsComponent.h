// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AIComponent.h"
#include "AIActionsComponent.generated.h"

UCLASS(ClassGroup=("Fortnite"))
class VERSEAIBASE_API UAIActionsComponent : public UAIComponent
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UAIActionsHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

};

