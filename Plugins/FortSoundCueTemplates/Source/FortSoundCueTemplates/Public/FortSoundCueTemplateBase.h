// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "SoundCueTemplate.h"
#include "FortSoundCueTemplateBase.generated.h"

class UAudioComponent;
class UFortSoundCueTemplateDefaults;
class UObject;

UCLASS(Abstract, HideCategories=("object", "Object"))
class FORTSOUNDCUETEMPLATES_API UFortSoundCueTemplateBase : public USoundCueTemplate
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(Category="Auditioning", meta=(CallInEditor="true"))
	virtual void Preview();
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="TemplateSettings")
	void ReloadDefaultSettings();
#endif

#if WITH_EDITOR
	UFUNCTION(Category="Auditioning", meta=(CallInEditor="true"))
	virtual void StopPreview();
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	float TemplateVolumeMultiplier;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	float TemplatePitchMultiplier;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	FVector2D PitchModulationRange;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	FVector2D VolumeModulationRange;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	FVector2D StartDelay;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UFortSoundCueTemplateDefaults> TemplateDefaults;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="FortSoundCueTemplateBase")
	bool bEditDefaultSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Instanced, Category="FortSoundCueTemplateBase", meta=(EditCondition="bEditDefaultSettings"))
	TObjectPtr<UFortSoundCueTemplateDefaults> DefaultTemplateSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> PreviewComponent;
#endif

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSubclassOf<UObject> SoundCueTemplateClass;
#endif

};

