// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimNotify_PlayNiagaraEffect.h"
#include "Effects/FortNiagaraCascadeMigration.h"
#include "FortAnimNotify_PlayNiagaraEffectWithBackup.generated.h"

class UParticleSystem;

UCLASS(HideCategories=("Object", "Object", "Object"), meta=(DisplayName="Play Niagara Particle Effect With Backup"))
class UFortAnimNotify_PlayNiagaraEffectWithBackup : public UAnimNotify_PlayNiagaraEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="NiagaraSystem")
	EFXType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify", meta=(DisplayName="Cacade System"))
	TObjectPtr<UParticleSystem> BackupTemplate;

};

