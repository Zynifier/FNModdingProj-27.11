// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSoundCueTemplateBase.h"
#include "FortSoundCueTemplateSimple.generated.h"

class USoundWave;

UCLASS(Abstract, HideCategories=("object", "Object"))
class FORTSOUNDCUETEMPLATES_API UFortSoundCueTemplateSimple : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves")
	TArray<TObjectPtr<USoundWave>> Variations;
#endif

};

