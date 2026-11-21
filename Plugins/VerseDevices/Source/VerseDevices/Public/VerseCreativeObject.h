// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseMovableObjectBase.h"
#include "VerseCreativeObject.generated.h"

class AActor;

UCLASS(Abstract)
class VERSEDEVICES_API UVerseCreativeObject : public UVerseMovableObjectBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, SaveGame, Category="VerseCreativeObject", meta=(DisplayName="Actor"))
	TObjectPtr<AActor> SavedActor;

};

