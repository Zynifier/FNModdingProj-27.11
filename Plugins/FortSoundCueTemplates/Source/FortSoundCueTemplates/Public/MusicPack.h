// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSoundCueTemplateBase.h"
#include "MusicPack.generated.h"

class USoundWave;

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UMusicPack : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MusicData")
	TObjectPtr<USoundWave> MusicLoop;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MusicData")
	uint8 bCopyrightedAudio : 1;
#endif

};

