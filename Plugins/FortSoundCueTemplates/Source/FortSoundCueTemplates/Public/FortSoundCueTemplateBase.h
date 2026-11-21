// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "SoundCueTemplate.h"
#include "UObject/ObjectSaveContext.h"
#include "FortSoundCueTemplateBase.generated.h"

class UAudioComponent;
class UFortSoundCueTemplateDefaults;
class UObject;
class USoundAttenuation;
class USoundClass;
class USoundNode;
class USoundWave;
struct FAudioParameter;
struct FDistanceDatum;
struct FModulatorContinuousParams;

#if WITH_EDITOR
struct FFortSoundCueTemplatePendingPinLink
{
	int32 ChildIndex = INDEX_NONE;
	FName PinName;
};

struct FFortSoundCueTemplateNodeParams
{
	TObjectPtr<USoundNode> ParentNode = nullptr;
	int32 Row = 0;
	int32 Column = 1;
	int32 InputPinIndex = 0;
	bool bAllowRootNode = true;
	bool bSetAsParent = true;
	bool bResetInputPinIndex = false;
	TArray<FFortSoundCueTemplatePendingPinLink> PendingPinLinks;
};
#endif

UCLASS(Abstract, HideCategories=("object", "Object"))
class FORTSOUNDCUETEMPLATES_API UFortSoundCueTemplateBase : public USoundCueTemplate
{
	GENERATED_BODY()

public:
	UFortSoundCueTemplateBase(const FObjectInitializer& ObjectInitializer);

	virtual bool CanBeClusterRoot() const override;
	virtual void PostInitProperties() override;
	virtual void PreSave(FObjectPreSaveContext ObjectSaveContext) override;
	virtual void PostLoad() override;
	virtual void Serialize(FArchive& Ar) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void LoadTemplateDefaultSettings() override;

protected:
	virtual void ApplyBaseSettings(USoundCue& SoundCue) const;
	virtual void ApplyConcurrencySettings(USoundCue& SoundCue) const;
	virtual void ApplySubmixSettings(USoundCue& SoundCue) const;
	virtual void ApplyBusSettings(USoundCue& SoundCue) const;
	virtual void ApplySettings(USoundCue& SoundCue) const;
	virtual USoundNode* AddDelayNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FVector2D& DelayRange) const;
	virtual USoundNode* AddModulatorNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FVector2D& VolumeRange, const FVector2D& PitchRange) const;
	virtual USoundNode* AddContinuousModulatorNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FModulatorContinuousParams& VolumeParams, const FModulatorContinuousParams& PitchParams) const;
	virtual USoundNode* AddParamCrossFadeNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FName& ParamName, const TArray<FDistanceDatum>& CrossFadeInput) const;
	virtual USoundNode* AddSwitchNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FName& ParamName) const;
	virtual USoundNode* AddSoundClassNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, USoundClass* SoundClass) const;
	virtual USoundNode* AddAttenuationNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, USoundAttenuation* Attenuation) const;
	virtual USoundNode* AddLicensedContentSwitcherNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, bool bLooping, bool bLinkMuteOthersPin) const;
	virtual void AddChildNode(USoundCue& SoundCue, USoundNode* ParentNode, USoundNode* ChildNode, int32 InputPinIndex) const;
	virtual void AddWavePlayerNodes(USoundCue& SoundCue, const FFortSoundCueTemplateNodeParams& Params, const TArray<USoundWave*>& Waves, bool bLooping, bool bAllowBranchCulling) const;

public:
	UFUNCTION(Category="Auditioning", meta=(CallInEditor="true"))
	virtual void Preview();

	UFUNCTION(BlueprintCallable, Category="TemplateSettings")
	void ReloadDefaultSettings();

	UFUNCTION(Category="Auditioning", meta=(CallInEditor="true"))
	virtual void StopPreview();

protected:
	virtual bool GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const;
	virtual void ValidateTemplateData();

	template <class T>
	T* ConstructNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params) const
	{
		T* Node = nullptr;
		if (!Params.bAllowRootNode || Params.ParentNode || SoundCue.FirstNode)
		{
			Node = &ConstructSoundNodeChild<T>(SoundCue, Params.ParentNode, Params.Column, Params.Row, Params.InputPinIndex);
			LinkPendingPinLinks(*Node, Params);
			if (Params.bSetAsParent)
			{
				if (Params.ParentNode)
				{
					++Params.Column;
				}
				Params.ParentNode = Node;
			}
		}
		else
		{
			Node = &ConstructSoundNodeRoot<T>(SoundCue);
			if (Params.bSetAsParent)
			{
				Params.ParentNode = Node;
			}
		}

		if (Params.bResetInputPinIndex)
		{
			Params.InputPinIndex = 0;
		}

		return Node;
	}

	template <class T>
	T* GetDefaultTemplateSettings() const
	{
		return Cast<T>(DefaultTemplateSettings);
	}

	static void LinkPendingPinLinks(USoundNode& Node, FFortSoundCueTemplateNodeParams& Params);

	void UpdatePreviewParameters();
	void UpdateSoundCueTemplateClass();
	void UpdateTemplateDefaults();

public:
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
	TObjectPtr<UClass> SoundCueTemplateClass;
#endif

};
