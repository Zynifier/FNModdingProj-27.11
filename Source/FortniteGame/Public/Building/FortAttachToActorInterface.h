// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAttachToActorInterface.generated.h"

class AActor;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortAttachToActorInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortAttachToActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Attachment")
	virtual AActor* GetActorAttachedTo() const;

	UFUNCTION(BlueprintCallable, Category="Attachment")
	virtual void SetActorAttachedTo(AActor* ActorAttachedTo);

};

